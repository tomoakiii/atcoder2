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
    ll H,W;
    cin >> H >> W;
    vector G(H, vector<int>(W, 4));
    rep(i,H) {
        rep(j,W) {
            int cnt=4;
            if(i == 0) cnt--;
            if(i == H-1) cnt--;
            if(j == 0) cnt--;
            if(j == W-1) cnt--;
            G[i][j] = cnt;
        }
    }
    rep(i,H) {
        rep(j,W) cout<<G[i][j]<<" \n"[j==W-1];
    }
    return 0;
}