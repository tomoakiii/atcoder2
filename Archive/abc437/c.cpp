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


void solve(){
    ll N; cin>>N;
    vector<ll> W(N), P(N);
    vector<pair<ll, int>> WP(N);
    ll wei = 0;
    rep(i,N) {
        cin>>W[i]>>P[i];
        WP[i].first = P[i] + W[i];
        WP[i].second = i;
        wei += W[i];
    }
    sort(WP.rbegin(), WP.rend());
    ll pow = 0;
    ll ans = N;
    for(auto [wp, i]: WP) {
        ll w = W[i], p = P[i];
        wei -= w;
        wei -= p;
        ans--;
        if(wei <= 0) {
            cout<<ans<<endl;
            return;
        }
    }
}



int main(){
    ll T; cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}