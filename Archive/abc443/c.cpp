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
    ll N,T;
    cin >> N >> T;
    bool flg = true;
    ll ed = 0;
    ll ans = 0;
    rep(i,N) {
        ll a; cin>>a;
        if(a <= ed) continue;
        ans += a - ed;
        ed = a + 100;
    }
    if(T>ed) ans += T - ed;
    cout << ans << endl;
    return 0;
}