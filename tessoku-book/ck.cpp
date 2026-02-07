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
typedef long double ld;
int main(){
    ld N; cin>>N;
    ld ng = 0, ok = N;
    while(ok - ng > 0.000001) {
        ld c = (ok+ng)/2;
        if(c*c*c+c>N) ok = c;
        else ng=c;
    }
    printf("%Lf\n", ok);
    return 0;
}