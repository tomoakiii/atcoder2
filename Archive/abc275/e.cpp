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
typedef modint998244353 mint;
int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    mint invM = 1;
    invM = invM / M;
    vector<mint> dp(N+1);
    dp[0] = 1;
    while(K--) {
        vector<mint> dp2(N+1);
        rep(i, N) {
            rep (j, M) {
                ll nx = i + j + 1;
                if (nx > N) {
                    ll d = nx - N;
                    nx = N - d;
                }
                dp2[nx] += dp[i] * invM;
            }
        }
        swap(dp, dp2);
    }

    mint ans = 1;
    rep(i, N) ans -= dp[i];
    cout << ans.val() << endl;
    return 0;
}