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
typedef modint1000000007 mint;
int main(){
    ll N;
    cin >> N;
    string S; cin>>S;
    vector<mint> dp(N+1);
    dp[0]=1;
    for(int i=1;i<=N;i++){
        if(S[i-1]=='#')continue;
        if(i-1>=0) dp[i]+=dp[i-1];
        if(i-2>=0) dp[i]+=dp[i-2];
        if(i-3>=0) dp[i]+=dp[i-3];
    }
    cout<<dp[N].val()<<endl;
    return 0;
}