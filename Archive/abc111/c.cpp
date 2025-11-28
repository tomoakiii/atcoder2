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
    vector<ll> V(N);
    rep(i,N) cin>>V[i];
    map<ll,ll> c0, c1;
    rep(i,N/2) {
        c0[V[i*2]]++;
        c1[V[i*2 + 1]]++;
    }
    vector<pair<ll,ll>> p1, p2;
    for(auto [c,v]: c0) {
        p1.push_back({v,c});
    }
    for(auto [c,v]: c1) {
        p2.push_back({v,c});
    }
    sort(p1.rbegin(), p1.rend());
    sort(p2.rbegin(), p2.rend());
    ll ans = INF;
    if(p1[0].second != p2[0].second) {
        chmin(ans, (N/2 - p1[0].first) + (N/2 - p2[0].first));
    }
    if(p1[0].second != p2[1].second) {
        chmin(ans, (N/2 - p1[0].first) + (N/2 - p2[1].first));
    }

    if(p1[1].second != p2[0].second) {
        chmin(ans, (N/2 - p1[1].first) + (N/2 - p2[0].first));
    }
    cout<<ans<<endl;
    return 0;
}