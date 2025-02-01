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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    int x[2], y[2];
    int cnt = 0;
    rep(i, H) rep(j, W) {
        if(S[i][j] == 'o') {
            x[cnt] = j;
            y[cnt] = i;
            cnt++;
        }
    }
    if(x[0] > x[1]) swap(x[0], x[1]);
    if(y[0] > y[1]) swap(y[0], y[1]);
    cout << x[1] - x[0] + y[1] - y[0] << endl;
    return 0;
}