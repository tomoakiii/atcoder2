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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll a, b; cin >> a >> b;
    ll ans = 1;
    ll MOD= 1000000007;
    ll p = a;
    while(b) {
        p %= MOD;
        if(b%2) ans *= p;
        b /= 2;
        ans %= MOD;
        p *= p;
    }
    cout << ans << endl;
    return 0;
}