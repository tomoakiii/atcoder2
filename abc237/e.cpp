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
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);

        uv[v].emplace_back(u);
    }
    vector<ll> P(N, -INF);
    P[0] = 0;
    priority_queue<pli> que;    
    que.push({0, 0});    
    ll mx = 0;    
    while(!que.empty()) {
        auto [p, q] = que.top();        
        que.pop();
        if(P[q] > p) continue;
        for(auto nx: uv[q]){
            ll delta = (H[q] >= H[nx]) ? H[q] - H[nx] : 2 * (H[q] - H[nx]);
            if(P[nx] < P[q] + delta){
                P[nx] = P[q] + delta;
                chmax(mx, P[nx]);
                que.push({P[nx], nx});
            } 
        }
    }
    cout << mx << endl;
    return 0;
}