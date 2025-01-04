#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N, M;
    cin >> N >> M;
    vector uv(N, vector<int>{});
    int mn = INFi;
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
        chmin(mn, u);
        chmin(mn, v);
    }
    ll ans = 0;
    rep(i, N) {
        auto& p = uv[i];
        sort(p.begin(), p.end());
        int it = lower_bound(p.begin(), p.end(), i) - p.begin();
        if (it == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}