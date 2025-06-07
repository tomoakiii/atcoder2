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
    ll H,W,K;
    cin >> H >> W >> K;

    ll M = 2*K;
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
    
    ll x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    x0--, y0--, x1--, y1--;
    
    vector dpx(K+1, vector<mint>(2)); // 0: there x1, 1: not there x1
    vector dpy = dpx;
    rep(nxy,2){
        mint h = 1;
        if(x1 == x0) {            
            dpx[0][0] = 1;            
        } else {
            dpx[0][0] = 0;
        }
        dpx[0][1] = 1 - dpx[0][0];

        for(int i = 1; i <= K; i++) {
            h *= H-1;
            dpx[i][0] = dpx[i-1][1];
            dpx[i][1] = h - dpx[i][0];
        }
        swap(x0, y0); swap(x1, y1); swap(H,W); swap(dpx, dpy);
    }

    mint ans = 0;
    for(ll i=0; i<=K; i++) {        
        ans += comb(K, i) * dpx[i][0] * dpy[K-i][0];
    }
    cout << ans.val() << endl;
    return 0;
}

