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
typedef pair<ll,int> pli;
int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    vector<ll> toll(N);
    rep(i,K) {
        int l; ll c; cin>>l>>c;
        l--;
        toll[l]=c;
    }
    vector<ll> cost(N,INF);
    cost[0]=toll[0];
    priority_queue<pli,vector<pli>,greater<pli>> que;
    que.push({cost[0],0});
    while(!que.empty()){
        auto [v,cur]=que.top();
        que.pop();
        if(cost[cur]<v) continue;
        for(auto [nx,w]:uv[cur]){
            if(chmin(cost[nx], cost[cur]+w+toll[nx])) {
                que.push({cost[nx],nx});
            }
        }
    }
    cout<<cost[N-1]<<endl;
    return 0;
}