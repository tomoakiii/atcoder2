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
    ll N,C;
    cin >> N >> C;
    vector<ll> B(N),W(N);
    rep(i,N) cin>>W[i]>>B[i];
    vector<ll> dp(C+1);
    rep(i,N){
        auto dp_new = dp;
        rep(j,C){
            ll nx = j + W[i];
            if(nx <= C) chmax(dp_new[nx], dp[j] + B[i]);
        }
        swap(dp,dp_new);
    }
    ll ans = 0;
    rep(j,C+1){
        chmax(ans,dp[j]);
    }
    cout<<ans<<endl;
    return 0;
}