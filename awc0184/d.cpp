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
    ll N,W,K;
    cin >> N >> W >> K;
    vector<ll> H(N);
    rep(i,N)cin>>H[i];
    vector dp(N+1, vector<ll>(K+1,INF));
    dp[0][0]=0;
    rep(i,N){
        rep(j,K+1)chmin(dp[i+1][j],dp[i][j]+H[i]);
        rep(j,K){
            rep(k,W){
                if(i+k+1>N)continue;
                chmin(dp[i+k+1][j+1],dp[i][j]);
            }
        }
    }
    ll ans=INF;
    rep(j,K+1)chmin(ans,dp[N][j]);
    cout<<dp[N][K]<<endl;
    return 0;
}