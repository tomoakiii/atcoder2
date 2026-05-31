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
    double l=0, r=101;
    auto func = [&](double x)->double{
        return A*x + B*sin(C*x*M_PI);
    };
    double thr = 100;
    while(true) {
        double c = (l+r)/2;
        double f = func(c);
        cerr << c << " " << f << endl;
        if(abs(f-thr) < 0.00000001) {
            printf("%.15f\n", c);
            return 0;
        }
        if(f > 100.) r=c;
        else l=c;
    }

    return 0;
}