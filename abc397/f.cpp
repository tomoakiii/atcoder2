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
    ll N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll M = 3e5+10;
    vector<ll> cl(M, INF), cr(M, 0);
    vector<bool> visit(M, false);
    rep(i,N) {
        chmin(cl[A[i]], i);
        chmax(cr[A[i]], i);
        visit[A[i]] = true;
    }

    ll ans = 0;
    vector<int> col(N);
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<int>(M, 0));        
    rep(i, M) {
        if (!visit[i]) continue;
        LS.apply(cl[i], cr[i]+1, 1);
        else LS.apply(x, x+W, 1);            
    
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