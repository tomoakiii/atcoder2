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
    double a,b,h,m;
    cin>>a>>b>>h>>m;
    double ah = h / 12 * 2 * M_PI;
    double am = m / 60 * 2 * M_PI;
    double xh = a * cos(ah), yh = a * sin(ah);
    double xm = b * cos(am), ym = b * sin(am);
    double dx = xh - xm, dy = yh - ym;
    printf("%.10f", sqrt(dx*dx + dy*dy) );

    return 0;
}