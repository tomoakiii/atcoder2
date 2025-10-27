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
    int N = S.size();
    vector<mint> dp(13);
    dp[0] = 1;
    for(char c : S) {

        int ic = c - '0';
        vector<mint> dp_new(13);
        rep(i,13) {
            int nx = (i*10+ic)%13;
            dp_new[nx] += dp[i];
        }
        swap(dp, dp_new);
    }
    cout<<dp[5].val()<<endl;
    return 0;
}