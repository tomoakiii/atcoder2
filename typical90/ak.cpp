#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define repab(i, a, b) for (int i = a; i <= b; i++)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

using S = ll;
using F = ll;
S op(S l, S r) {return max(l, r);}
S e() {return -INF;}
S mapping (F l, S r) {return max(l, r);}
F composition (F l, F r) {return max(l, r);}
F id() {return -INF;}


int main(){
    int W, N;
    cin >> W >> N;
    vector<int> R(N), V(N), L(N);
    
    rep(i,N) {
        cin >> L[i] >> R[i] >> V[i];
        R[i]--, C[i]--;        
    }    
    
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<ll>(W+1, 0));
    vector<int> ans(N);
    
    rep(i,N){
        rep(j, W){

            ll k = LS.prod(j, j+R[i]); // max(Cp ~ Cp+Lp)    
        }
        
        LS.apply(C[p], C[p]+L[p], k+1); // Cp~Cp+Lp = k+1
        ans[p] = H - k;        
    }
    rep(i, N) cout << ans[i] << endl;
    return 0;
}