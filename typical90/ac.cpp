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
S e() {return -INF;}
S mapping (F l, S r) {return max(l, r);}
F composition (F l, F r) {return max(l, r);}
F id() {return -INF;}


int main(){
    int W, N;
    cin >> W >> N;
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<int>(W, 0));
    while(N--) {
        int L, R;
        cin >> L >> R;
        L--, R--;
        int k = LS.prod(L, R+1);
        LS.apply(L, R+1, k+1);
        cout << k+1 << endl;
    }

    return 0;
}