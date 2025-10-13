#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

double degree(double rad){
  return rad / M_PI * 180;
}

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
int main(){
    double a,b,X; cin>>a>>b>>X;
    double ori = a*b;
    X /= a;
    double rem = ori - X;
    if(X >= a*b/2) {
      double theta = atan(2*rem/a/a);
      printf("%.10f\n", degree(theta));
    } else {
      double theta = atan(b*b/2/X);
      printf("%.10f\n", degree(theta));
    }
    return 0;
}