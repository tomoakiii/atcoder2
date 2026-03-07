// https://atcoder.jp/contests/abc228/editorial/2932
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
typedef modint mint;
template <class Type> class PowMod {
private:
    ll MMax = 100; // 2^100 = 1.2E30 までのダブリング
public:
    vector<Type> PM;
    // p^x
    PowMod(ll p) {
        PM.resize(MMax);
        PM[0] = 1;
        PM[1] = p;
        for(ll i=1; i<MMax-1; i++) {
            PM[i+1] = PM[i]*PM[i];
        }
    }

    // p^x
    Type GetPow(ll x) {
        Type ret = 1;
        int id = 1;
        while(x) {
            if(x%2 == 1) {
                ret *= PM[id];
            }
            id++;
            x /= 2;
        }
        return ret;
    }
};


int main(){
    ll K, X;
    cin>>K>>X;
    ll Mod = 10007 * X;
    // ll Mod = 100000007 * X;

    mint::set_mod(Mod);
    PowMod<mint> pow10(10);

    mint sm = 0;

    ll M = 100;
    vector<mint> pow11(M);
    pow11[0] = 1;
    pow11[1] = 11;
    vector<ll> digit(M);
    digit[0] = 1;
    digit[1] = 2;
    for(ll i=1; i<M-1; i++) {
        pow11[i+1] = pow11[i] * pow10.PM[i+1] + pow11[i];
        digit[i+1] = digit[i] * 2;
    }

    rep(i, K) {
        ll c,l; cin>>c>>l;
        ll l2 = l;
        mint k1 = pow10.GetPow(l);
        mint k2 = 0;
        int id = 0;
        while(l2) {
            if(l2%2 == 1) {
                k2 = k2 * pow10.GetPow(digit[id]) + pow11[id];
            }
            id++;
            l2 /= 2;
        }
        sm = k1 * sm + k2 * c;
        // cerr<<sm.val()<<endl;
    }
    ll x = sm.val();
    ll ans = x / X;
    cout << ans << endl;
    return 0;
}