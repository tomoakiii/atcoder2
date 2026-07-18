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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> dp(N+1,-INF);
    dp[0]=0;
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
        chmax(dp[i+1], dp[i]+A[i]);
        if(i+1-K>=0) chmax(dp[i+1], dp[i+1-K]);
    }
    cout << dp[N] << endl;
    return 0;
}