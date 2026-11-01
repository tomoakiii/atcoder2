#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N;
    M = N-1;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> C(N);
    rep(i,N) {
        cin>>C[i];
        C[i]--;
    }
    int mx=-1; int node1;
    vector<ll> subsize(N,1);
    auto fn1 = [&](auto fn1, int cur, int pre, int d)->void{
        if(chmax(mx, d)) node1=cur;
        for(auto nx:uv[cur]){
            if(nx==pre) continue;
            fn1(fn1, nx, cur, d+1);
            subsize[cur]+=subsize[nx];
        }
    };
    fn1(fn1, 0, -1, 0);

    int R=-1;
    vector<ll> dist(N,INF);
    auto fn2 = [&](auto fn2, int cur, int pre, int d)->void{
        dist[cur]=d;
        chmax(R,d);
        for(auto nx:uv[cur]){
            if(nx==pre) continue;
            fn2(fn2, nx, cur, d+1);
        }
    };
    int st = node1;
    fn2(fn2, st, -1, 0);


    queue<int> que;
    vector<int> deg(N);
    rep(i,N){
        deg[i]=uv[i].size();
        if(deg[i]==1){
            deg[i]=0;
            que.push(i);
        }
    }

    vector<int> route;
    while(!que.empty()){
        auto q=que.front();
        que.pop();
        route.push_back(q);
        for(auto nx:uv[q]){
            deg[nx]--;
            if(deg[nx]==1) {
                deg[nx]=0;
                que.push(nx);
            }
        }
    }

    set<int> parents;
    int root = -1;
    if(R%2 == 0){
        root = route.back();
        for(auto nx : uv[root]) parents.insert(nx);
    } else {
        parents.insert(route.back());
        route.pop_back();
        parents.insert(route.back());
    }
    int id=0;
    int R2=(R/2)-1;
    if(R%2==1)R2++;
    vector<vector<ll>> ColInd(N);
    for(auto p:parents){

        map<ll,ll> Colors;
        auto fn3 = [&](auto fn3, int cur, int pre, int d, int par)->void{
            if(d==R2) Colors[C[cur]]++;
            for(auto nx:uv[cur]){
                if(nx==pre) continue;
                if(parents.contains(nx)) continue;
                fn3(fn3, nx, cur, d+1, par);
            }
        };
        fn3(fn3, p, root, 0, id);
        id++;
        for(auto [c, v] : Colors){
            ColInd[c].push_back(v);
        }
    }
    ll ans = 0;
    rep(i,N){
        ll sm = 0;
        int sz = ColInd[i].size();
        if(sz<2) continue;
        rep(j, sz) {
            sm += ColInd[i][j];
        }
        rep(j, sz-1){
            sm -= ColInd[i][j];
            ans += ColInd[i][j] * sm;
        }
    }
    cout << ans << endl;

    return 0;
}