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
typedef modint1000000007 mint;
int main(){
    ll H,W,K;
    cin >> H >> W >> K;
    vector sw(1ll<<(W-1), vector<int>(W));
    vector<int> st(W);
    rep(i,W) st[i] = i;
    int ind = 0;
    rep(kk, 1ll<<(W-1)) {
        vector<bool> line(W-1);
        rep(i,W-1) {
            if(kk>>i&1) line[i] = true;
        }
        bool flg = true;
        auto nx = st;
        rep(i,W-2) {
            if(line[i] && line[i+1]) flg = false;
        }
        if(!flg) continue;
        rep(i,W-1) if(line[i]) swap(nx[i],nx[i+1]);
        sw[ind++] = nx;
    }
    vector<mint> now(W);
    now[0] = 1;
    rep(i,H) {
        vector<mint> pro(W);
        rep(j,ind) {
            rep(k,W) {
                pro[sw[j][k]] += now[k];
            }
        }
        swap(pro,now);
    }
    cout << now[K-1].val() << endl;
    return 0;
}