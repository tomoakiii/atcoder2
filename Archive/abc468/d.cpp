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
    string S; cin>>S;
    ll N=S.size();
    vector dp(N, vector<ll>(N,INF));
    rep(i,N)dp[i][i]=0;
    rep(i,N-1){
        dp[i][i+1]=(S[i]==S[i+1])?0:1;
    }
    auto func=[&](auto func, int l, int r)->void{
        if(dp[l][r] < INF) return;
        if(dp[l+1][r-1] == INF){
            func(func,l+1,r-1);
        }
        if(dp[l][r-1] == INF){
            func(func,l,r-1);
        }
        if(dp[l+1][r] == INF){
            func(func,l+1,r);
        }
        ll v=1;
        if(S[l]==S[r]) v=0;
        dp[l][r]=dp[l+1][r-1]+v;
    };
    func(func, 0, N-1);
    ll ans=0;
    rep(l,N)for(int r=l;r<N;r++){
        if(dp[l][r]<=1) {
            // cerr<<l<<" "<<r<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}