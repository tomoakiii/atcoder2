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

int main(){
    ll H,W,N,M;
    cin >> H >> W >> N >> M;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];
    vector<set<int>> vh(H+2), vw(W+2);
    for(auto &v: vh) v.insert(0), v.insert(W+1);
    for(auto &v: vw) v.insert(0), v.insert(H+1);
    
    rep(i,M) {
        int C, D; cin >> C >> D;
        vh[C].insert(D);
        vw[D].insert(C);
    }
    vector lh(H+2, vector<int>(W+2)), lw(W+2, vector<int>(H+2)); 
    rep(i, N) {
        auto v = vh[A[i]].upper_bound(B[i]);
        ll r = *v;
        v--;
        ll l = *v;
        lh[A[i]][l+1]++;
        lh[A[i]][r]--;
    }
    rep(i, N) {
        auto v = vw[B[i]].upper_bound(A[i]);
        ll r = *v;
        v--;
        ll l = *v;
        lw[B[i]][l+1]++;
        lw[B[i]][r]--;
    }
    for(auto &l: lh) rep(i, W+1) l[i+1] += l[i];
    for(auto &l: lw) rep(i, H+1) l[i+1] += l[i];
    ll ans = 0;
    rep(i,H+1) rep(j,W+1) {
        if(lh[i][j] > 0 || lw[j][i] > 0 ) ans++;
    }
    cout << ans << endl;
    return 0;
}