/* https://imoz.jp/algorithms/imos_method.html */
/*  */

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
    int N;
    cin >> N;
    const int M = 1001;
    vector Grid(M, vector<int>(M));
    rep(i,N) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 2次元区間和。
        // 矩形領域に+1を加算する。左上の座標に+1、右上と左下は-1、右下に+1
        Grid[y1][x1]++;
        Grid[y1][x2]--;
        Grid[y2][x2]++;
        Grid[y2][x1]--;
    }
    // 横方向に累積和
    rep(i,M) rep(j,M-1) Grid[i][j+1] += Grid[i][j];
    // 縦方向に累積和
    rep(i,M-1) rep(j,M) Grid[i+1][j] += Grid[i][j];

    // 各Grid[y][x]の中身は、その座標に紙が何枚重なっているか
    vector<int> ans(N+1);
    rep(i,M) rep(j,M) {
        ans[Grid[i][j]]++;
    }
    rep(i,N) cout<<ans[i+1]<<endl;
    return 0;
}