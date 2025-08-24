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
    int H,W,K; cin>>H>>W>>K;
    vector<string> G(H);
    rep(i,H) cin>>G[i];
    ll sm = 0;
    rep(y, H) rep(x, W) if(G[y][x] == '#') sm++;
    ll ans = 0;
    rep(i, 1<<H) {
        rep(j, 1<<W) {
            ll sm2 = sm;
            rep(y, H) {
                rep(x, W) {
                    if((i >> y & 1) || (j >> x & 1)) {
                        if(G[y][x] == '#') sm2--;
                    }
                }
            }
            if(sm2 == K) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}