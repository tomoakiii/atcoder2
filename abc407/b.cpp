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
    ll X, Y;
    cin >> X >> Y;
    int cnt = 0;
    for(int i=1; i<=6; i++) for(int j=1; j<=6; j++) {
        if(i+j >= X || abs(i-j)>=Y) cnt++;
    }
    printf("%.10f\n", (double)cnt / (double)36);
    return 0;
}