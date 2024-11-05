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
    double a, b;
    cin >> a >> b;
    if (a > b) swap(a, b); // a < b
    if (sqrt(3) * b/2 > a) swap(a,b);
    double ok = b, ng = sqrt(a*a + b*b);
    while ((ng - ok)*1e11 > 1) {
        double l = (ok + ng)/2;
        double theta = acos(b/l);
        if (theta > M_PI/6) {
            ng = l;
            continue;
        }
        if (a > l * cos(M_PI/6 - theta)) {
            ok = l;
        } else {
            ng = l;
        }
    }
    cout << setprecision(24) <<  ok << endl;
    return 0;
}