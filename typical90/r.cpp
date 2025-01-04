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
typedef pair<ll, int> pli;
int main(){
    double T, L, X, Y;
    cin >> T >> L >> X >> Y;
    ll Q;
    cin >> Q;
    double omega = 2 * M_PI / T;
    while(Q--){
        double E;
        cin >> E;
        double x = 0, y = -L / 2 * sin(omega * E);
        double z = L/2 * (1 - cos(omega * E));
        double l = sqrt((x-X)*(x-X) + (y-Y)*(y-Y));
        double ans = abs(180/M_PI * atan(z/l));
        printf("%.12f\n", ans);
    }
   return 0;
}