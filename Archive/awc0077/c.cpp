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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];

    vector<ll> dp(S+1,INF);
    dp[0]=0;
    rep(i,N){
        auto dp_new=dp;
        rep(j,S){
            int nx=j+A[i];
            if(nx>S)break;
            chmin(dp_new[nx],dp[j]+1);
        }
        swap(dp,dp_new);
    }
    if(dp[S]>=INF) cout<<-1<<endl;
    else cout<<dp[S]<<endl;
    return 0;
}