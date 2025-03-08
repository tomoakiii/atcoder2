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
    vector uv(N, vector<pair<ll, ll>>{});
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].push_back({v, w});
        uv[v].push_back({u, w});
    }
    ll mn = INF;
    auto f = [&](auto f, int cur, ll hist, ll x) -> void {
        if(cur == N-1) {
            chmin(mn, x);
            return;
        }
        for (auto [nx, w]: uv[cur]) {
            if((hist >> nx) & 1 > 0) continue;
            ll x2 = x ^ w;
            ll hist2 = hist | (1<<nx);
            f(f, nx, hist2, x2);
        }
    };
    f(f, 0, 1, 0);
    cout << mn << endl;
    return 0;
}