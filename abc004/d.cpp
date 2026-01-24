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
    ll sft = 10000;
    ll M = sft * 10;
    vector<ll> mv(M);
    rep(i,M-1) mv[i+1] = mv[i] + i+1;
    auto func = [&](ll nm, ll tg, ll cr) -> ll {
        ll ret = 0;
        ll d = abs(tg - cr);
        if(d+1 >= nm) {
            // one direction
            ret += mv[d];
            ret += nm * (d + 1 - nm);
        } else {
            ret += mv[d];
            ll k = nm - 1 - d;
            if(k>=0) ret += mv[k];
        }
        return ret;
    };
    vector<ll> rt(M,INF), bt(M,INF);
    rep(r, M) {
        ll nr = r + R - 1;
        if(nr >= M) break;
        rt[nr] = func(R, r, sft - 100);
    }
    rep(b, M) {
        ll nb = b + B - 1;
        if(nb >= M) continue;
        bt[b] = func(B, b, sft + 100);
    }
    rep(r, M-1) {
        chmin(rt[r+1], rt[r]);
    }
    for(int b=M-1; b>=1; b--) {
        chmin(bt[b-1], bt[b]);
    }
    ll ans = INF;
    for(ll g=sft-1000; g<=sft+1000; g++) {
        ll sm = func(G, g, sft);
        sm += rt[g-1];
        sm += bt[g+G];
        chmin(ans, sm);
    }
    cout << ans << endl;
    return 0;
}