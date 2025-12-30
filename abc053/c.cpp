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
    ll X;
    cin >> X;
    ll last = 6;
    ll ans = 0;
    ll p = X / 11;
    ans += 2*p;
    X %= 11;
    while(X > 0) {
        X -= last;
        ans++;
        if(last == 6) last = 5;
        else last = 6;
    }
    cout << ans << endl;
    return 0;
}