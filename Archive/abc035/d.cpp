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
typedef pair<ll, pair<int,ll>> pli;
int main(){
    ll N,M,T;
    cin>>N>>M>>T;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector uv(N, vector<pair<int, ll>>{});
    vector vu(N, vector<pair<int, ll>>{});

    rep(i,M) {
        int u,v; cin>>u>>v;
        ll c; cin>>c;
        u--,v--;
        uv[u].push_back({v,c});
        vu[v].push_back({u,c});
    }

    vector<ll> dist(N,INF);
    dist[0] = 0;
    auto dist2 = dist;
    priority_queue<pli,vector<pli>,greater<pli>> que;
    rep(kkk,2) {
        que.push({0, {0,0}});
        while(!que.empty()) {
            auto [dummy, ppp] = que.top();
            que.pop();
            auto [cur, ds] = ppp;
            if(dist[cur] < ds) continue;
            for(auto [nx,c]: uv[cur]){
                if(dist[nx] <= dist[cur] + c) continue;
                dist[nx] = dist[cur] + c;
                que.push({c, {nx, dist[nx]}});
            }
        }
        swap(uv,vu); swap(dist,dist2);
    }
    ll ans = 0;
    rep(i,N) {
        ll t = dist[i] + dist2[i];
        if(t > T) continue;
        chmax(ans, (T-t)*A[i]);
    }
    cout << ans << endl;
    return 0;
}