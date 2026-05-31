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
    ll R,C,X,Y,D,L;
    cin>>R>>C>>X>>Y>>D>>L;
    Combination<mint> CM(R*C);
    auto func = [&](ll x, ll y)->mint{
        auto s = x*y;
        if(s < D+L) return 0;
        auto c = CM.comb(s, D+L);
        return c;
    };
    mint a = func(X,Y-1);
    mint b = func(X-1,Y);
    mint c = func(X-1,Y-1);
    mint d = func(X,Y);
    mint ans = d - a - b + c;
    ans *= CM.comb(D+L,D);
    ans *= (C-Y+1);
    ans *= (R-X+1);
    cout << ans.val() << endl;
    return 0;
}