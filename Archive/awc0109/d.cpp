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
    ll N,C,K;
    cin >> N >> C >> K;
    vector<ll> B(N),W(N);
    rep(i,N) cin>>B[i]>>W[i];
    vector dp(C+1, vector<ll>(K+1));
    rep(i,N){
        auto dp_new = dp;
        rep(j,C+1){
            ll nx = j + W[i];
            rep(k,K+1) if(nx <= C) chmax(dp_new[nx][k], dp[j][k] + B[i]);
            rep(k,K) {
                ll nx = j + W[i]/2;
                if(nx <= C) chmax(dp_new[nx][k+1], dp[j][k] + B[i]);
            }
        }
        swap(dp,dp_new);
    }
    ll ans = 0;
    rep(k,K+1){
        rep(j,C+1){
            chmax(ans,dp[j][k]);
        }
    }
    cout<<ans<<endl;
    return 0;
}