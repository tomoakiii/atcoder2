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
typedef long double ld;
int main(){
    ll N; cin>>N;
    string S, T; cin>>S;
    T=S;
    reverse(T.begin(), T.end());
    vector dp(N+1, vector<int>(N+1));
    cerr << S << " " << T << endl;
    rep(i,N) {
        rep(j,N) {
            if(S[i] == T[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                chmax(dp[i+1][j+1], dp[i][j+1]);
                chmax(dp[i+1][j+1], dp[i+1][j]);
            }
        }
    }
    int ans = 1;
    /*
    rep(i,N+1) {
        rep(j,N+1) cerr << dp[i][j] << " ";
        cerr << endl;
    }
    */
    for(int i=1; i<=N-1; i++) {
        chmax(ans, 2*dp[i][N-i]);
        chmax(ans, 2*dp[i][N-i-1]+1);
    }
    cout << ans << endl;
    return 0;
}