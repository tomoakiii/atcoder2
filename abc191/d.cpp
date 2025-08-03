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
    double x, y, r;
    cin >> x >> y >> r;
    auto jdg = [&](double a, double b)->bool{
        double dr = (a-x)*(a-x) + (b-y)*(b-y);
        return dr*dr <= r*r;
    };
    for(ll xs = ceil(x-r); xs <= floor(x+r); xs++) {
        ll ys = floor(y);
        if(jdg(xs,ys))
    }
    return 0;
}