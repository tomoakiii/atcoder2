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
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    ll ans = 0;
    rep(i,N) {
        for(auto nx: uv[i]) {
            if(nx < i) continue;
            for(auto nx2: uv[nx]) {
                if(nx2 < nx) continue;
                for(auto nx3 : uv[nx2]) {
                    if (nx3 == i) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}