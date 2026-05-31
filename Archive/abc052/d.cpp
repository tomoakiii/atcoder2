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
    ll N,A,B;
    cin >> N >> A >> B;
    ll last; cin>>last;
    ll ans = 0;
    rep(i,N-1) {
        ll x; cin>>x;
        ll d = x-last;
        ans += min(A*d, B);
        last = x;
    }
    cout << ans << endl;
    return 0;
}