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
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    ll mn = (A+C-1)/C;
    ll mx = B/C;
    ll Cit = mx - mn + 1;
    mn = (A+D-1)/D;
    mx = B/D;
    ll Dit = mx - mn + 1;
    ll CD = lcm(C,D);
    mn = (A+CD-1)/(CD);
    mx = B/(CD);
    ll CDit = mx - mn + 1;
    cout << B-A+1 - Cit - Dit + CDit << endl;
    return 0;
}