#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
template <typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template <typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

using S = int;
using F = int;
S op(S l, S r) { return max(l, r); }
S e() { return 0; }
S mapping(F l, S r) { return r += l; }
F composition(F l, F r) { return l + r; }
F id() { return 0; }

int main() {
    ll T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string St;
        cin >> St;
        int lc = 0, rc = 0;
        vector<ll> rn(N), ln(N);
        rep(i, N) {
            char c = St[i];
            rn[i] = rc;
            ln[i] = lc;
            if (c == 'R') {
                rc++;
                lc = 0;
            } else {
                lc++;
                rc = 0;
            }
        }
        lazy_segtree<S, op, e, F, mapping, composition, id> ST(vector<int>(N, 0));
        rep(i, N) {
            ST.apply(0, rn[i], 1);
            ST.apply(ln[i], N, 1);
        }
        rep(i, N) cout << N - ST.get(i) << " ";
        cout << endl;
    }

    return 0;
}
