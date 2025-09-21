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
    string S; cin>>S;
    int N = S.size();
    vector<ll> dp(2020, 0);
    ll ans = 0;
    rep(i,N) {
        vector<ll> dp_new(2020,0);
        ll nm = (S[i]-'0');
        dp_new[nm] = 1;
        rep(j, 2020){
            ll nj = j*10 + nm;
            nj%=2019;
            dp_new[nj] += dp[j];
        }
        ans += dp_new[0];
        swap(dp,dp_new);
    }
    cout << ans << endl;
    return 0;
}