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
    string S; cin>>S;
    string ch = "chokudai";
    vector<mint> dp(ch.size());
    for(auto c:S) {
        if(c == ch[0]) dp[0]++;
        else {
            rep(i, ch.size()-1) {
                if(c == ch[i+1]) dp[i+1] += dp[i];
            }
        }
    }
    cout<<dp[ch.size()-1].val()<<endl;
    return 0;
}