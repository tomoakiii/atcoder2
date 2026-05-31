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
    vector uv(N, vector<int>{});
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<bool> visit(N);
    ll ans = 0;
    
    auto f = [&](auto f, int cur, int pre) {
        ans++;
        if (ans >= 1E6) {
            ans = 1E6;
            return;
        }
        visit[cur] = true;
        for(auto d: uv[cur]) {
            if(visit[d]) continue;
            f(f, d, cur);
        }
        visit[cur] = false;
    };
    f(f, 0, -1);
    cout << ans << endl;
    return 0;
}