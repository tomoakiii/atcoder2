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
    double A,B,C; cin>>A>>B>>C;
    double x = 100./ A - 0.25/C;
    double t;
    double mn = 100;
    double interval = 0.5/C/1000000;
    while(x <= 100./ A + 0.25/C) {
        if(x <= 0) continue;
        double f = A*x + B*sin(C*x*M_PI);
        if(chmin(mn, abs(f-100.))) {
            t = x;
            printf("%.10f\n", f);
        }
        x = x + interval;
    }
    printf("%.10f\n", t);

    return 0;
}