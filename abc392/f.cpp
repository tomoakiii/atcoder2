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
    cin >> N;
    vector<ll> P(N);
    rep(i,N) {
        cin>>P[i];
        P[i]--;
    }
    vector<int> A(N), ans(N);    

    rep(i,N) A[i] = i;
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(A);
    for(int i=N-1; i>=0; i--) {
        int p = P[i];
        int ng = -1, ok = N-1;
        while(ok - ng > 1) {
            int c = (ng+ok)/2;
            if(LS.get(c) < P[i]) {
                ng = c;
            } else {
                ok = c;
            }
        }
        ans[ok] = i+1;    
        LS.apply(ok, N, -1);
    }
    rep(i,N) cout << ans[i] << " ";
    cout << endl;
    return 0;
}