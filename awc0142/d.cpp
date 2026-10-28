#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M, T;
    cin >> N >> M >> T;
    vector<ll> P(N);
    ll mx = 0;
    rep(i,N) {
        cin>>P[i];
        chmax(mx, P[i]);
    }
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }


    auto check = [&](ll risk)->bool{
        typedef pair<ll,int> pli;
        priority_queue<pli, vector<pli>, greater<pli>> que;
        vector<ll> dist(N, INF);
        int st = 0;
        dist[st] = 0;
        que.push({dist[st],st});
        while(!que.empty()){
            auto [q, i] = que.top();
            que.pop();
            if(dist[i] < q)continue;
            for(auto [nx,w]:uv[i]){
                if(P[nx] > risk) continue;
                if(chmin(dist[nx], q+w))que.push({dist[nx],nx});
            }
        }
        if(dist[N-1]>T) return false;
        else return true;
    };

    ll ok = mx, ng = max(P[0], P[N-1]) - 1;
    while(ok - ng > 1){
        ll c = (ok+ng)/2;
        if(check(c)) ok=c;
        else ng=c;
    }
    cout << ok << endl;
    return 0;
}