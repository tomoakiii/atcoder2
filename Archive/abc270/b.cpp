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
    ll x, y, z;
    cin >> x >> y >> z;
    if (x < 0) {
        x *= -1;
        y*=-1;
        z*=-1;
    }
    ll dist = -1;
    if (y < x && y > 0) {
        if (z < y && z > 0) {
            dist = x;
        } else if (z < 0) {
            dist = x - 2 * z;
        }
    } else {
        dist = x;
    }
    cout << dist << endl;
    return 0;
}