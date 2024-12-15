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
typedef tuple<ll, ll, ll> tplll;

int main(){
    ll N, X, K;
    cin >> N >> X >> K;
    vector<tplll> CPU(N);
    rep(i,N) {
        ll p, u, c;
        cin>>p>>u>>c;
        tplll t = {c, p, u};
        CPU[i] = t;
    }
    sort(CPU.begin(), CPU.end());
    vector dp(N+1, vector(X+1, vector<ll>(2, -INF)));
    dp[0][0][0] = 0;
    ll lscm = 0;
    ll lsc = -1;
    rep(i,N){
        auto [c, p, u] = CPU[i];
        if(c != lsc) {
            rep(j, X) {
                if(p + j > X) continue;
                dp[i+1][j][0] = max(dp[i][j][0], dp[i][j][1]);
                dp[i+1][j+p][1] = dp[i+1][j][0] + K + u;
            }
        } else {
            rep(j, X) {
                if(p + j > X) continue;
                dp[i+1][j+p][1] = max(dp[i][j][0] + K + u, dp[i][j][1] + u);
                dp[i+1][j][0] = dp[i][j][0];
            }
        }
        lsc = c;
    }
    ll ans=0;
    rep(j, X+1){
        rep(k,2) {
            chmax(ans, dp[N][j][k]);
        }
    }
    cout << ans << endl;
    return 0;
}