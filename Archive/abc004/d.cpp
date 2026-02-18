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
    ll R,G,B;
    cin >> R>>G>>B;
    ll M = 10000;
    vector<ll> mv(M);
    rep(i,M-1) mv[i+1] = mv[i] + i+1;
    auto func = [&](ll nm, ll tg, ll cr) -> ll {
        ll ret;
        ll d = tg - cr;
        if(d > 0) {
            ret = mv[d+nm-1] - mv[d-1];
            return ret;
        }
        d *= -1;
        if(d <= nm-1) {
            // one direction
            ll rm = nm-(d+1);
            ret = mv[d] + mv[rm];
            return ret;
        }
        ret = mv[d] - mv[d-nm];
        return ret;
    };

    ll ans = INF;
    for(ll g=-1000; g<=1000; g++) {
        ll sm = func(G, g, 0);
        ll mnr= INF;
        int rr;
        for(ll r=-1300; r<=1000; r++) {
            if(r+R-1 >= g) break;
            if(chmin(mnr, func(R, r, -100))) rr=r;
        }
        ll mnb = INF;
        int bb;
        for(ll b=g+G; b<=1000; b++) {
            if(chmin(mnb, func(B, b, 100))) bb = b;
        }
        ll tot = sm+mnr+mnb;
        if(chmin(ans, tot)){
           // cerr << tot << " || " << rr << ":" << mnr << " " << g << ":" << sm << " " << bb << ":" << mnb << endl;
        }
    }
    cout << ans << endl;
    return 0;
}