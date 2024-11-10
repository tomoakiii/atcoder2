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
    ll L;
    cin >> L;
    ll N1, N2;
    cin >> N1 >> N2;
    vector<ll> va(N1), la(N1), vb(N2), lb(N2);
    vector lasm = la, lbsm = lb;
    map<pair<ll, ll>, ll> mp;

    ll p = 0; 
    rep(i, N1) {
        ll v, l;
        cin >> v >> l;
        mp[{p, 0}] = v;
        p += l;
    }
    p = 0;
    rep(i, N2) {
        ll v, l;
        cin >> v >> l;
        mp[{p, 1}] = v;
        p += l;
    }
    mp[{L, 0}] = -1;
    ll ans = 0;
    ll cur = 0, v[2] = {-1, -2}; 
    for(auto m: mp) {
        ll p = m.first.second;
        ll xv = m.second;
        ll ln = m.first.first - cur;
        cur = m.first.first;
        if (v[0] == v[1]) {
            ans += ln;
        }
        v[p] = xv;
    }

    
    cout << ans << endl;
    return 0;
}