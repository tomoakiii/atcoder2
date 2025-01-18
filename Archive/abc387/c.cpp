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
    auto f = [&](ll x) -> ll{
        string in = to_string(x);
        int lm = 0;
        int sz = in.size();        
        vector<int> v(sz);
        vector dp(sz+1, vector(10, vector(2, vector<ll>(2))));
        for(int i = 0; i < sz; i++) {
            int v = in[i] - '0';
            rep(j, 10) {
                if(j < v){
                    rep(p, 10) {
                        dp[i+1][j][1] += dp[i+1][p][0];
                        dp[i+1][j][1] += dp[i+1][p][1];
                    }
                }
                if(j != 0) {
                    rep(p, 10) {
                        dp[i+1][j][0][1] += dp[i+1][p][0][0];
                    }
                }
            }
            v[i] = (int)(in[i] - '0');
            if(i != 0) chmax(lm, v[i]);
        }
        
        for(int i = 1; i < sz-1; i++) {
            ans += v[i] * pow(lm, sz-i-1);
        }
        ans += 1 + min(lm, v[sz-1]);
        return ans;
    };

    // reverse(L.begin(), L.end());    
    auto f = [&](ll x) -> ll{
        string in = to_string(x);
        int lm = 0;
        int sz = in.size();        
        vector<int> v(sz);
        for(int i = 0; i < sz; i++) {
            v[i] = (int)(in[i] - '0');
            if(i != 0) chmax(lm, v[i]);
        }
        ll ans = 0;
        for(ll vs = 1; vs < v[0]; vs++) {
            ans += pow((vs - 1), sz-1);
        }
        for(int i = 1; i < sz-1; i++) {
            ans += v[i] * pow(lm, sz-i-1);
        }
        ans += 1 + min(lm, v[sz-1]);
        return ans;
    };

    rep(i, 100) {
        cout << i << " " << f(i) << endl;
    }

    ll fr = f(R);
    ll fl = f(L-1);
    cout << fr - fl << endl;

    return 0;
}