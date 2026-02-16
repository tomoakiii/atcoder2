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
    string S,T; cin>>S>>T;
    int s=S.size(), t=T.size();
    vector dp(s+1, vector<ll>(t+1));
    rep(i,s) {
        rep(j,t) {
            chmax(dp[i+1][j+1],dp[i][j+1]);
            chmax(dp[i+1][j+1],dp[i+1][j]);
            if(S[i] == T[j]) chmax(dp[i+1][j+1],dp[i][j]+1);
        }
    }
    cout<<dp[s][t]<<endl;
}