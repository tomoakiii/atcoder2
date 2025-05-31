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


int main(){
    ll A, B, C, D;
    cin>>A>>B>>C>>D;
    ll M = 4e6;
    vector<mint> fct(M+1,1); // array of factorial. fct[k] = k!
    fct[1] = 1;
    for(ll i=2; i<=M; i++) {
        mint ip = i;
        fct[i] = fct[i-1] * ip;
    }

    vector<mint> rfct(M+1,1); // rmfct[k] = 1/k!
    rfct[M] = 1/fct[M];
    for(ll i=M; i>1; i--) {
        mint ip = i;
        rfct[i-1] = rfct[i] * ip;
    }

    // kCr = (k!)/(r!)/((k-r)!)
    
    auto comb = [&](ll n, ll k)->mint{
        if (n < k || k < 0) return 0;
        return fct[n] * rfct[k] * rfct[n-k];
    };
    

    map<ll, unordered_map<ll, mint>> mpp;
    map<ll, mint> mpf;    
    mint ans = 0;
    //cout << comb(834150, 21994).val() << endl;
    for(ll k = 0; k<=C; k++) {
        mint p = comb(A+k+B, B);
        p *= comb(C-k+D-1, D-1);
        ans += p;
    }
    
    cout << ans.val() << endl;
    return 0;
}