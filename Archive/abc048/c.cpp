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
    ll N,x;
    cin >> N >> x;
    ll a; cin>>a;
    ll ans = 0;
    if(a > x) {
        ans += a-x;
        a = x;
    }
    rep(i,N-1) {
        ll b; cin>>b;
        if(a+b > x) {
            ans += a+b-x;
            b = x - a;
        }
        a = b;
    }
    cout << ans << endl;
    return 0;
}