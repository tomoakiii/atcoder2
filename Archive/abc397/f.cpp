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
    unordered_map<ll,int> last;
    rep(i,N) {
        cin>>A[i];
        last[A[i]] = i;
    }
    
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<int>(M, 0));
    
    LS.apply(0, x+W, 1);  

    cout << ans << endl;
    return 0;
}