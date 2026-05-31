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

template <class Type> class PowMod {
private:
    ll MMax = 100; // 2^100 = 1.2E30 までのダブリング
    vector<Type> PM;
public:
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
    typedef modint998244353 mint;
    PowMod<mint> PM(2);
    rep(i,10) {
        cout << PM.GetPow(i).val() << endl;
    }
    return 0;
}