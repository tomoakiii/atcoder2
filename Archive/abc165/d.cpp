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
    ll a,b,n;
    cin>>a>>b>>n;
    ll x;
    if(n >= b-1) {
        x = b-1;
    } else {
        x = n;
    }
    ll ans = (a*x/b) - a * (x/b);
    cout << ans << endl;
    return 0;
}