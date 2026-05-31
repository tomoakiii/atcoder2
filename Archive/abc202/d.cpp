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
// nCk = nC(n+n-k)
int main(){
    ll A,B,K; cin>>A>>B>>K;
    vector dp(A+1, vector<ll>(B+1));
    rep(i,A+1) dp[i][0] = 1;
    rep(j,B+1) dp[0][j] = 1;

    rep(i,A) {
        rep(j,B) {
            dp[i+1][j+1] += dp[i][j+1] + dp[i+1][j];
        }
    }
    string S(A+B, 0);
    ll a = A, b = B;
    ll k = 0;
    rep(i, A+B) {     
        if(a==0) {
            S[i]='b';
            continue;
        }
        ll c = dp[a-1][b];
        if(b==0) S[i]='a';        
        else if(k + c < K) {
            S[i] = 'b';
            k += c;
            b--;
        }
        else {
            S[i] = 'a';
            a--;
        }
    }

    cout << S << endl;
    return 0;
}