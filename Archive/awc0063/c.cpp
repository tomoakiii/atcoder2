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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    ll mx=0;
    mint sm=0;
    rep(i,N) {
        ll a; cin>>a;
        sm+=a;
        chmax(mx,a);
    }
    sm-=mx;
    PowMod<mint> PM(2);
    auto mmx = PM.GetPow(K) * mx;
    sm+=mmx;
    cout<<sm.val()<<endl;
    return 0;
}