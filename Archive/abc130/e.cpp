// https://atcoder.jp/contests/abc221/tasks/abc221_e

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


int main(){
    int N,M; cin>>N>>M;
    vector<ll> A(N),B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    vector dp(N+1, vector<mint>(M+1,0));
    rep(i,M+1) dp[0][i] = 1;
    rep(i,N) {
        ll a = A[i];
        dp[i+1][0] = 1;
        rep(j,M){
            ll b=B[j];
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j];
            if(a!=b) dp[i+1][j+1]-=dp[i][j];      
        }
    }
    /*
    rep(i,N+1) {
        rep(j,M+1) cerr<<dp[i][j].val()<<" ";
        cerr<<endl;
    }
    */
    cout<<dp[N][M].val()<<endl;
    return 0;
}

/*

   -   1    1

-  1   1   1

1  1   2   3

1  1   3   6



   -   3    1

-  1   1   1

1  1   1   2

3  1   2   3


*/