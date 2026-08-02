#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T;
    cin >> T;
    while(T--){
        ll N; cin>>N;
        ll q = sqrtl(N);
        ll ans = 2 * (q * (q - 1));
        ll rm = N - q*q;
        if(rm >= q) {
            if(q > 0) ans += 2*q - 1;
            rm -= q;
        }
        if(rm > 0) ans += 2*rm - 1;
        cout << ans << endl;
    }
    return 0;
}