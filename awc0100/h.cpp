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
    ll N, M;
    cin >> N >> M;
    priority_queue<pair<ll,int>> que;
    vector<ll> B(N);
    rep(i,N){
        cin>>B[i];
        if(i==0)B[i]=INF;
        que.push({B[i],i});
    }
    vector uv(N, vector<pair<ll,int>>{});

    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(B[v],v);
    }
    rep(i,N) sort(uv[i].rbegin(),uv[i].rend());
    vector<int> ans;
    vector<bool> visit(N);
    while(!que.empty()){
        auto [q,i]=que.top();
        que.pop();
        if(visit[i])continue;
        auto dfs=[&](auto dfs, int cur)->void{
            ans.push_back(cur+1);
            visit[cur]=true;
            for(auto [w,nx]:uv[cur]){
                if(visit[nx]) continue;
                dfs(dfs, nx);
                break;
            }
        };
        dfs(dfs, i);
    }
    rep(i,N) cout<<ans[i]<<" \n"[i==N-1];
    return 0;
}