// https://atcoder.jp/contests/abc221/tasks/abc221_e

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
    ll N;
    cin >> N;
    Combination<mint> CMB(2*N);
    for(ll k = 1; k <= N; k++){
        mint ans = 0;
        for(ll a = 1; (a-1)*k+1 <= N; a++){
            ll R = N - ((k-1)*(a-1) + a);
            mint x = CMB.fct[R+a];
            mint y = CMB.rfct[R];
            mint z = CMB.rfct[a];
            ans += x * y * z;
        }
        cout << ans.val() << endl;
    }
    return 0;
}