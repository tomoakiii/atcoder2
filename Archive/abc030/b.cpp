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
    double n,m; cin>>n>>m;
    if(n > 12) n -= 12;
    n += m/60;
    n = n * 360 / 12;
    m = m * 360 / 60;
    if(n > m) swap(n,m);
    double ans = m-n;
    chmin(ans, 360+n-m);
    printf("%.10f\n",ans);
    return 0;
}