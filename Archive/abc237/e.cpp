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

typedef pair<ll, int> pli;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> H(N);
    rep(i,N) cin>>H[i];
    vector uv(N, vector<pair<ll, ll>>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        ll d = H[u] - H[v];
        if(d > 0) {
            uv[u].emplace_back(v, 0); // neg = happy
            uv[v].emplace_back(u, d); // pos
        } else {
            uv[u].emplace_back(v, -d); // pos
            uv[v].emplace_back(u, 0); // neg
        }
        
        
    }
    vector<ll> P(N, INF);
    P[0] = 0;    

    priority_queue<pli, vector<pli>, greater<pli>> que;
    que.push({0,0});
    while(!que.empty()) {
        auto [c, q] = que.top();
        que.pop();
        if(P[q] < c) continue;        
        for(auto [nx, c2]: uv[q]){
            if(P[nx] > c + c2){
                P[nx] = c + c2;
                que.push({P[nx], nx});
            }
        }
    }

    ll mx = 0;
    rep(i, N) {
        chmax(mx, H[0]-H[i]-P[i]);
    }
    cout << mx << endl;
    return 0;
}