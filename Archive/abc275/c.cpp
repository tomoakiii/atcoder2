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
    vector<string> S(9);
    rep(i,9) {
        cin >> S[i];
    }
    ll ans = 0;
    auto jdg = [&](int nx, int ny)->bool{
        if (nx < 0 || nx >= 9 || ny < 0 || ny >= 9) {
            return false;
        }
        if (S[nx][ny] == '#') return true;
        else return false;

    };

    rep(i, 9) rep(j, 9) {
        for(int y=-8; y<=8; y++) for (int x=-8; x<=8; x++) {
            if (x == 0 && y == 0) continue;
            int nx = i + x;
            int ny = j + y;            
            int nx2 = nx + y;
            int ny2 = ny - x;
            int nx3 = i + y;
            int ny3 = j - x;            
            if (jdg(i, j) && jdg(nx, ny) && jdg(nx2, ny2) && jdg(nx3, ny3)) {
                ans++;
            }
        }
    }

    cout << ans/4 << endl;
    return 0;
}