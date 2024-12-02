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
    string S;
    cin >> S;
    string atc = "atcoder";
    vector<mint> dp(8);
    dp[0] = 1;
    rep(i,N) {
        vector old = dp;
        rep(k, 7) {
            if(S[i] == atc[k]) dp[k+1] += old[k];
        }
    }
    cout<<dp[7].val()<<endl;
    return 0;
}