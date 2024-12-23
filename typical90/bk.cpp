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
    int H, W;
    cin >> H >> W;
    vector P(H, vector<int>(W, 0));
    rep(i,H) rep(j,W) cin>>P[i][j];
    
    vector<int> Dc(W);
    rep(j,W) {
        rep(i, H) {
            Dc[j] += P[][]1<<i;
        }
    }
    return 0;
}