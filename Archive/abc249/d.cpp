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
    ll N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> mp;
    rep(i,N) {
        cin>>A[i];
        mp[A[i]]++;
    }
    ll ans = 0;    
    vector<pair<ll, ll>> vp;
    ll mx = 0;
    for(auto m: mp) {
        vp.push_back({m.first, m.second});
        chmax(mx, m.first);
    }
    
    rep(i, vp.size()) {
        ll ca = vp[i].second;
        rep(j, vp.size()) {
            ll cb = vp[j].second*vp[i].second;
            ll tgt = vp[i].first * vp[j].first;
            if(tgt > mx) break;
            if(mp.contains(tgt)) ans+=cb*mp[tgt];
        }
    }
    cout << ans << endl;
    return 0;
}