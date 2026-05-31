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
    string S;
    cin >> S;
    int N=S.size();
    vector<mint> dp(3);
    dp[S[0]-'a'] = 1;
    for(int i=1; i<N; i++) {
        auto dp_new = dp;
        dp_new[S[i]-'a']++;
        for(char c='a'; c<='c'; c++) {
            int ci = c-'a';
            int si = S[i]-'a';
            if(S[i] != c){
                dp_new[si]+=dp[ci];
            }
        }
        swap(dp,dp_new);
    }
    mint ans = 0;
    rep(i,3) ans += dp[i];
    cout<<ans.val()<<endl;
    return 0;
}