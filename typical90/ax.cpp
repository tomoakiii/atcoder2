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
typedef modint1000000007 mint;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tiii;
typedef modint1000000007 mint;

int main(){
    ll N, L;
    cin >> N >> L;
    vector<mint> dp(N+1, 0);
    dp[0] = 1;
    rep(i,N) {
        dp[i+1] += dp[i];
        if(i+L <= N) dp[i+L] += dp[i]; 
    }
    cout << dp[N].val() << endl;
    return 0;
}