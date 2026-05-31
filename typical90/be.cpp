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
    ll N, S;
    cin >> N >> S;    
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    vector dp(N+1, vector<ll>(S+1, -INF));
    dp[0][0] = 1;
    rep(i,N) {
        rep(k, S) {
            if(dp[i][k] == -INF) continue;
            if(k+A[i] <= S) dp[i+1][k+A[i]] = 1;
            if(k+B[i] <= S) dp[i+1][k+B[i]] = 1;
        }
    }
    if(dp[N][S] == -INF) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<string> ans(N);
    ll c = S;
    for(int i=N-1; i>=0; i--) {
        if(c-A[i] >= 0 && dp[i][c-A[i]] == 1) {
            ans[i] = "A";
            c -= A[i];
        } else {
            ans[i] = "B";
            c -= B[i];
        }
    }
    for(auto s: ans) cout << s;
    cout << endl;
    return 0;
}