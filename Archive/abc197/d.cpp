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
    int N; cin>>N;
    double x0, y0, x2, y2; cin>>x0>>y0>>x2>>y2;
    double xc = (x0+x2)/2, yc = (y0+y2)/2;
    double vx = (x0-xc), vy = (y0-yc);
    double xa = vx*cos(2*M_PI/N) - vy*sin(2*M_PI/N);
    double ya = vx*sin(2*M_PI/N) + vy*cos(2*M_PI/N);
    printf("%.10f %.10f", xa+xc, ya+yc);

    return 0;
}