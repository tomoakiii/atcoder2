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
    vector<ll> V(N), W(N);
    rep(i,N) cin>>V[i]>>W[i];

    vector dp(K+1, vector<ll>(2,-INF)); //0:non, 1;yes
    dp[0][0] = 0;
    rep(i,N){
        vector dp2(K+1, vector<ll>(2,-INF)); //0:non, 1;yes
        rep(j,K+1){
            chmax(dp2[j][0], max(dp[j][0],dp[j][1]));
            ll nx = j+W[i];
            if(nx > K) continue;
            chmax(dp2[nx][1], dp[j][0] + V[i]);
        }
        swap(dp,dp2);
    }
    ll ans = 0;
    rep(i,K+1){
        chmax(ans, max(dp[i][0],dp[i][1]));
    }
    cout<<ans<<endl;
    return 0;
}