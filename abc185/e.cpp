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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    vector dp(N+1, vector<ll>(M+1));

    rep(i,N) rep(j,M) {
        if(A[i] == B[j]) chmax(dp[i][j], dp[i-1][j]+1);
    }
    return 0;
}