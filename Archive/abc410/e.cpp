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
    ll N,H,M;
    cin >> N>>H>>M;
    vector<ll> A(N), B(N);
    rep(i,N) cin>>A[i]>>B[i];
    vector dp(N+1, vector<ll>(H+1, INF));
    dp[0][0] = 0;
    rep(i,N) {
        bool flg = false;
        rep(a,H+1) {
            ll na = a + A[i];
            ll nb = dp[i][a] + B[i];
            if(na <= H && dp[i][a] <= M) {
                chmin(dp[i+1][na], dp[i][a]);
                flg = true;
            }
            if(nb <= M) {
                chmin(dp[i+1][a], nb);
                flg = true;
            }
        }
        if(!flg) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<N<<endl;
    return 0;
}