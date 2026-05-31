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

using S = ll;
using F = ll;
S op(S l, S r) {return min(l, r);}
S e() {return INF;}
S mapping (F l, S r) {return r+=l;}
F composition (F l, F r) {return l+r;}
F id() {return 0;}


int main(){
    int N, Q;
    cin >> N >> Q;
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<ll>(N, 0));
    while(Q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int va = LS.get(a), vb = LS.get(b);
        if(va != vb) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        LS.apply(a, b+1, rand()*rand());
    }    
    return 0;
}