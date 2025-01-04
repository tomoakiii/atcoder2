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
    ll L, R;
    cin >> L >> R;
    // reverse(L.begin(), L.end());    
    auto f = [&](ll x) -> ll{
        string in = to_string(x);
        ll out = 0;
        int lm = 0;
        int sz = in.size();        
        vector<int> v(sz);
        for(int i = 0; i < sz; i++) {
            v[i] = (int)(in[i] - '0');
            if(i != 0) chmax(lm, v[i]);
        }
        vector dp(2, vector(sz+1, vector<ll>(lm+1)));
        dp[0][0][lm] = 1;
        rep(l, lm) {
            dp[1][0][l] = 1;
        }
        for(int i = 1; i < sz; i++){
            rep(l, lm+1) {
                if(l < v[i]) {
                    rep(k, lm+1) {
                        dp[1][i][l] += dp[0][i-1][k];
                    }
                } else if (l == v[i]) {
                    rep(k, lm+1) {
                        dp[1][i][l] += dp[0][i-1][k];
                    }                    
                }

                rep(k, lm+1) {
                    dp[1][i][l] += dp[1][i-1][k];
                }
            }
        }
        rep(k, lm+1) {
            out += dp[0][sz-1][k];
            out += dp[1][sz-1][k];
        }
        return out;
    };

    cout << f(R) - f(L-1) << endl;

    return 0;
}