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
    ll N; cin>>N;
    vector<ll> A(N), B(N);
    rep(i,N-1) cin>>A[i+1];
    rep(i,N-2) cin>>B[i+2];
    vector<ll> dp(N,INF);
    dp[0] = 0;
    rep(i,N-1) {
        chmin(dp[i+1], dp[i] + A[i+1]);
        if(i+2<N) chmin(dp[i+2], dp[i] + B[i+2]);
    }
    cout << dp[N-1] << endl;
}