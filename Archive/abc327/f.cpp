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

using S = int;
using F = int;
S op(S l, S r) {return max(l, r);}
S e() {return 0;}
S mapping (F l, S r) {return r+=l;}
F composition (F l, F r) {return l+r;}
F id() {return 0;}


int main(){
    int N, D, W;
    cin >> N >> D >> W;    
    const int M = 2E5+1;
    vector Y(M, vector<int>{});
    vector dY(M, vector<int>{});
    rep(i,N) {
        ll t, x;
        cin >> t >> x;        
        Y[t].emplace_back(x);
        if(t+D < M) dY[t+D].emplace_back(x);
    }
    ll ans = 0;
    vector<int> col(M);
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<int>(M, 0));        
    rep(t, M){        
        for(auto x: Y[t]){ 
            if(x+W>M) LS.apply(x, M, 1);
            else LS.apply(x, x+W, 1);            
        }
        for(auto x: dY[t]){
            if(x+W>M) LS.apply(x, M, -1);
            else LS.apply(x, x+W, -1);
        }        
        ll p = LS.all_prod();
        chmax(ans, p);
    }
    cout << ans << endl;
    return 0;
}