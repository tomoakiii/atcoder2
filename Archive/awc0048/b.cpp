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
    ll N;
    cin >> N;
    vector<ll> H(N),D(N);
    rep(i,N) cin>>H[i];
    rep(i,N) cin>>D[i];
    ll ans=0;
    vector<ll> dp(N);
    if(H[0]>0 && D[0]>0) dp[0]=1;
    for(int i=1; i<N; i++) {
        int p=0;
        if(H[i]>0 && D[i]>0) p=1;
        if(i>1) dp[i] = min(dp[i-1],dp[i-2])+p;
        else dp[i]=dp[i-1]+p;
    }
    cout<<dp[N-1]<<endl;
    return 0;
}