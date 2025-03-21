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
    ll N, X, Y;
    cin >> N >> X >> Y;
    X--, Y--;
    vector uv(N, vector<ll>{});
    rep(i,N-1) {
        int u,v;
        cin>>u>>v;
        u--, v--;        
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    
    }

    vector<int> dist(N, INF);    
    auto f=[&](auto f, int cur, int pre, int d)->void {
        for (auto nx : uv[cur]){
            if (nx == pre) continue;
            if (dist[nx] < d+1) {
                continue;
            }
            dist[nx] = d+1;
            f(f, nx, cur, d+1);
        }        
    };
    dist[Y] = 0;
    f(f, Y, -1, 0);
    auto f2=[&](auto f2, int cur, int pre)->void {
        cout << cur+1 << " ";
        if (cur == Y) return;
        for (auto nx : uv[cur]){
            if (nx == pre) continue;
            if (dist[nx] > dist[cur]) {
                continue;
            }
            f2(f2, nx, cur);
        }        
    };
    f2(f2, X, -1);    
    cout << endl;
    return 0;
}