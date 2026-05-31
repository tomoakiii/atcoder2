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
    ll L,R,D,U;
    cin >> L>>R>>D>>U;
    ll ans = 0;
    ll M = 1e6+10;
    // ll M = 4;
    for(ll x=0; x<=M; x++) {
        ll ymn = max(D, -x);
        ll ymx = min(U, x);
        ll xmn = max(L, -x);
        ll xmx = min(R, x);
        if(ymn > ymx || xmn > xmx) continue;
        ll sm = (ymx-ymn+1) * (xmx-xmn+1);
        // cerr << x << " " << sm << endl;
        if(x%2==1) {
            ans -= sm;
        } else {
            ans += sm;
        }
    }
    cout<<ans<<endl;
    return 0;
}