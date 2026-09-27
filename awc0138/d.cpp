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
    ll N,W,B;
    cin >> N >> W >> B;
    vector<ll> D(N),C(N);
    rep(i,N) cin>>D[i]>>C[i];
    vector dp(W+1,vector<ll>(3,-INF));
    dp[0][0] = 0;
    rep(i,N){
        vector dp2(W+1,vector<ll>(3,-INF)); 
        dp2[0][0] = 0;
        rep(j,W+1){
            chmax(dp2[j][0], max(dp[j][2],max(dp[j][1],dp[j][0])));
            ll nj = j+C[i];
            if(nj>W)continue;
            chmax(dp2[nj][2], max(dp[j][2]+D[i]+B,dp[j][1]+D[i]+B+B));
            chmax(dp2[nj][1], dp[j][0]+D[i]);
        }
        swap(dp,dp2);
    }
    ll ans=0;
    rep(i,W+1)chmax(ans, max(dp[i][0],max(dp[i][1],dp[i][2])));
    cout<<ans<<endl;
    return 0;
}