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
    ll N;cin>>N;
    ll sm=0;
    vector<ll>A(N);
    rep(i,N){
      cin>>A[i];
      sm+=A[i];
    }
    ll M=sm/2;
    vector<bool> dp(M+1);
    dp[0]=true;
    rep(i,N){
        auto dp2=dp;
        rep(j,M){
            if(!dp[j])continue;
            int nk = j+A[i];
            if(nk>M)continue;
            dp2[nk] = true;
        }
        swap(dp,dp2);
    }
    for(int i=M;i>=0;i--){
        if(dp[i]){
            ll x = sm-i;
            cout << x-i << endl;
            return 0;
        }
    }
    return 0;
}