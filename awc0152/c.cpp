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
typedef modint998244353 mint;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<mint> dp(K+1);
    dp[0]=1;
    rep(i,N){
        auto dp2=dp;
        ll a; cin>>a; a%=K;
        rep(j,K+1){
            ll nk=(j+a)%K;
            dp2[nk]+=dp[j];
        }
        swap(dp,dp2);
    }
    cout<<(dp[0]-1).val()<<endl;
    return 0;
}