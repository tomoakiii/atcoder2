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
    ll N,M;
    cin >> N >> M;
    set<int> st;
    rep(i,M) {
        ll a; cin>>a;        
        st.insert(a);
    }
    vector<mint> dp(N+2);
    dp[0] = 1;
    rep(i,N) {
        if(!st.contains(i+1)) dp[i+1] += dp[i];
        if(!st.contains(i+2)) dp[i+2] += dp[i];
    }
    cout << dp[N].val() << endl;
    return 0;
}