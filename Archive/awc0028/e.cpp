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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N), P(K);
    rep(i,N) cin>>A[i];
    rep(i,K) cin>>P[i];
    vector<mint> dp(N+1,1);
    rep(j,K-1) {
        vector<mint> dp_new(N+1,0);
        rep(i,N) {
            if(A[i]==P[j]) dp_new[i+1]+=dp[i];
        }
        rep(i,N) dp_new[i+1]+=dp_new[i];
        swap(dp,dp_new);
        // rep(i,N+1) cerr<<dp[i].val()<<" \n"[i==N];
    }
    mint ans = 0;
    rep(i,N) {
        if(A[i] == P[K-1]) ans+=dp[i];
    }
    cout<<ans.val()<<endl;
    return 0;
}