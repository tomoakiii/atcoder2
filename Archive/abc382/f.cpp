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
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> R(N), C(N), L(N);
    vector<pair<int, int>> vp{};
    rep(i,N) {
        cin>>R[i]>>C[i]>>L[i];
        R[i]--, C[i]--;
        vp.push_back({R[i], i});
    }
    sort(vp.rbegin(), vp.rend());
    vector<int> col(W);
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vector<int>(W, 0));
    vector<int> ans(N);
    
    for(auto m: vp){
        int p = m.second;
        int k = LS.prod(C[p], C[p]+L[p]);
        LS.apply(C[p], C[p]+L[p], k+1);
        ans[p] = H - k;        
    }
    rep(i, N) cout << ans[i] << endl;
    return 0;
}