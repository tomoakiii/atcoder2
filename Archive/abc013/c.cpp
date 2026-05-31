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
    ll N,H; cin>>N>>H;
    ll A,B,C,D,E; cin>>A>>B>>C>>D>>E;
    vector<ll> V(N+1, INF);
    ll ans = INF;
    rep(i,N+1) {
        ll st = H;
        ll pay = A * i;
        st += B * i;
        ll rm = N - i;
        if(st >= rm * E) {
            chmin(ans, pay);
            continue;
        }
        ll ng = 0, ok = rm;
        while(ok - ng > 1) {
            ll c = (ng + ok)/2;
            ll st2 = st + D * c;
            ll rm2 = rm - c;
            if(st2 > rm2 * E) ok = c;
            else ng = c;
        }
        pay += C*ok;
        chmin(ans, pay);
    }
    cout << ans << endl;
    return 0;
}