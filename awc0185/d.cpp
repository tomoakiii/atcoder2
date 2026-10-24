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
    ll N,K,C;
    cin >> N >> K >> C;
    vector dp(K+1,vector<ll>(C+1));
    rep(i,N){
        ll w,v;cin>>w>>v;
        auto dp2=dp;
        rep(k,K){
            ll nk=k+1;
            rep(c,C){
                ll nw=c+w;
                if(nw>C)break;
                chmax(dp2[nk][nw],dp[k][c]);
            }
        }
        swap(dp,dp2);
    }
    ll ans=0;
    rep(c,C+1)chmax(ans,dp[K][c]);
    cout<<ans<<endl;
    return 0;
}