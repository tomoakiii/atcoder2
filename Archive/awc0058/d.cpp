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
    ll N, M, K;
    cin >> N >> M >> K;
    K--;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v; ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v,w);
        uv[v].emplace_back(u,w);
    }
    typedef pair<ll,int> pli;
    auto func=[&](int st, int gl)->ll{
        vector<ll> dist(N, INF);
        dist[st]=0;
        priority_queue<pli,vector<pli>,greater<pli>> que;
        que.push({0,st});
        while(!que.empty()){
            auto [d,cur] = que.top();
            que.pop();
            if(dist[cur]<d) continue;
            for(auto [nx,w]:uv[cur]) {
                if(chmin(dist[nx], dist[cur]+w)) {
                    que.push({dist[nx],nx});
                }
            }
        }
        return dist[gl];
    };
    ll d1 = func(0,K);
    ll d2 = func(K,N-1);
    if(d1>=INF || d2>=INF) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<d1+d2<<endl;
    return 0;
}