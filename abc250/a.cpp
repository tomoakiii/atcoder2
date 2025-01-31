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
    int R, C;
    cin >> R >> C;
    R--, C--;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int ans = 0;
    rep(i, 4) {
        int ny = R + dy[i];
        int nx = C + dx[i];
        if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}