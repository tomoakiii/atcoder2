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
typedef pair<ll,ll> pll;
int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> P(N-1);
    vector uv(N, vector<int>{});
    rep(i,N-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uv[a].push_back(b);
        uv[b].push_back(a);
        P[i] = {a, b};
    }
    
    vector<int> cld(N);
    
    auto f = [&](auto f, int cur, int pre)->int{
        int sm = 1;
        for(auto nx: uv[cur]) {
            if(nx == pre) continue;
            cld[nx] += f(f, nx, cur);
            sm += cld[nx];
        }
        return sm;
    };
    cld[0] = f(f, 0, -1);
    ll ans = 0;
    for(auto [a, b] : P) {
        ll x = cld[a], y = cld[b];
        if(y > x) swap(x, y);
        ans += (N-y) * y;
    }
    cout << ans << endl;
    return 0;
}