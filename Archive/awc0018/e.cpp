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
    ll N,K,B;
    cin >> N>>K>>B;
    vector<ll> C(N),S(N);
    rep(i,N) cin>>C[i]>>S[i];

    vector dp(K+1,vector<ll>(B+1,INF));
    dp[0][0]=0;
    ll ans = 0;
    rep(i,N){
        rep(j,K){
            rep(k,B+1){
                if(dp[j][k] >=S[i]) continue;
                if(k+C[i] > B) continue;
                chmin(dp[j+1][k+C[i]], S[i]);
                chmax(ans,j+1);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}