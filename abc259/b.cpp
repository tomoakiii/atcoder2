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
    double a, b, d;
    int ai, bi, di; 
    cin>>a>>b>>d;
    double r = sqrt(a*a + b*b);
    double theta;
    if(abs(r)<0.000000001){
        theta = 0;
    } else {
        theta = acos(a/r);
        if (b<0) theta = 2*M_PI - theta;
    }
    theta += d/180*M_PI;
    printf("%.10f %.10f", r*cos(theta), r*sin(theta));
    return 0;
}