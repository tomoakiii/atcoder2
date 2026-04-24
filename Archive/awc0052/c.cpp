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
    ll N,S;
    cin >> N >> S;
    vector<ll> dp(S+1,-INF);
    dp[0]=0;
    rep(i,N) {
        ll v,c; cin>>v>>c;
        auto dp_new=dp;
        rep(j,S){
            if(j+c>S)break;
            chmax(dp_new[j+c],dp[j]+v);
        }
        swap(dp,dp_new);
    }
    if(dp[S]>0) cout<<dp[S]<<endl;
    else cout<<-1<<endl;
    return 0;
}