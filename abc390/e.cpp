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
    ll N, X;
    cin >> N >> X;
    vector A(3, vector<ll>{}), C(3, vector<ll>{});
    vector dp(3, vector<ll>(X+1, -INF));
    rep(i,N) {
        ll v,a,c;
        cin >> v >> a >> c;
        v--;
        A[v].emplace_back(a);
        C[v].emplace_back(c);        
    }

    int sz[3];
    rep(k, 3) {
        dp[k][0] = 0;
        sz[k] = (ll)A[k].size();
        rep(i, sz[k]) { 
            vector ndp = dp[k];
            rep(j, X+1) {                
                if(j+C[k][i] > X) continue;                
                chmax(ndp[j+C[k][i]], dp[k][j] + A[k][i]);
            }
            swap(ndp, dp[k]);
        }
    }
    rep(k,3) {
        ll mx = 0;
        rep(i, X+1) {
            chmax(mx, dp[k][i]);
            dp[k][i] = mx;
        }
    }
    ll ans = 0;
    rep(i, X+1) {
        rep(j, X+1-i) {
            ll k = (X - i - j);
            if(k < 0 || k > X) continue;
            ll tans = min(dp[0][i], min(dp[1][j], dp[2][k]));
            chmax(ans, tans);
        }
    }
    cout << ans << endl;
    return 0;
}