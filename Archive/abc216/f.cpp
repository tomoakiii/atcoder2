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
    ll N;
    cin >> N;
    vector<pair<ll,int>> A(N);
    vector<ll> B(N), Bs(N);
    rep(i,N) {
        cin>>A[i].first;
        A[i].second = i;
    }
    rep(i,N) cin>>B[i];
    sort(A.begin(), A.end());
    rep(i,N) {
        Bs[i] = B[A[i].second];
    }
    vector dp(N+1, vector<mint>(5001));
    mint ans = 0;
    dp[0][0] = 1;
    rep(i,N) {
        rep(j, 5001) {
            dp[i+1][j] += dp[i][j];
            ll nx = j + Bs[i];
            if(nx > 5000) continue;
            dp[i+1][nx] += dp[i][j];
            if(nx <= A[i].first) ans += dp[i][j];
        }
    }
    cout << ans.val() << endl;
    return 0;
}