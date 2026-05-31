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

template <class Type> class Combination{
public:
    vector<mint> fct{}; // array of factorial. fct[k] = k!
    vector<mint> rfct{}; // rmfct[k] = 1/k!
    Combination(int M){
        fct.resize(M+1, 1);
        rfct.resize(M+1, 1);
        for(ll i=2; i<=M; i++) {
            mint ip = i;
            fct[i] = fct[i-1] * ip;
        }
        rfct[M] = 1/fct[M];
        for(ll i=M; i>1; i--) {
            mint ip = i;
            rfct[i-1] = rfct[i] * ip;
        }
    }

    // kCr = (k!)/(r!)/((k-r)!)
    mint comb(ll n, ll k){
        if (n < k || k < 0) return 0;
        return fct[n] * rfct[k] * rfct[n-k];
    };

};


int main(){
    string S;
    cin >> S;
    map<char, ll> mp;
    for(auto c: S) mp[c]++;
    vector<mint> dp(5001);
    Combination<mint> CB(5001);
    for(auto [c, n]: mp) {
        vector dp_new = dp;
        for(ll k=1; k<=n; k++) {
            dp_new[k] += 1;
            for(ll j=1; j<5001; j++) {
                if(dp[j] == 0) continue;
                dp_new[j+k] += dp[j] * CB.fct[j+k] * CB.rfct[k] * CB.rfct[j];
            }
        }
        swap(dp, dp_new);
    }
    mint ans = 0;    
    rep(i, 5001) ans += dp[i];
    cout << ans.val() << endl;
    return 0;
}