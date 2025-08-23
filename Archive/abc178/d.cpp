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
    ll S;
    cin >> S;
    vector<mint> dp(S+1,0);

    dp[0] = 1;
    mint ans = 0;
    rep(i,S){
        vector<mint> dp_new(S+1, 0);
        for(int x = 0; x+3 <= S; x++) {
            dp_new[x+3] = dp[x];
        }
        rep(i,S) {
            dp_new[i+1] += dp_new[i];
        }
        swap(dp, dp_new);
        ans += dp[S];
    }
    cout<<ans.val()<<endl;
    return 0;
}