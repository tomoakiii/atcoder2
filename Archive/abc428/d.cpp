#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


ll getdig(ll x){
    ll d = 0;
    while(x) {
        x/=10;
        d++;
    }
    return d;
}

void solve(){
    ll C,D; cin>>C>>D;
    ll E = C+D;
    ll d = getdig(C+D);
    ll d0 = getdig(C);
    ll e10[100];
    e10[0] = 1;
    rep(i,19) e10[i+1] = e10[i] * 10;
    ll ans = 0;
    for(int i = d0 ; i <= d; i++) {
        ll mn = max(C*e10[i] + C, C*e10[i] + e10[i-1]);
        ll mx;
        if(i == d) {
            mx = C*e10[i] + C+D;
        } else {
            mx = C*e10[i] + (e10[i]-1);
        }
        if(mn > mx) break;
        ll s = sqrtl(mn);
        if(s*s == mn) s--;
        ll sm = sqrtl(mx);
        ans += sm - s;
        // cerr << "debug: " << mx << " " << mn << endl;
    }
    cout << ans << endl;
}


int main(){
    ll T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}