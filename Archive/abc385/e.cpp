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
    vector uv(N, vector<ll>{});
    rep(i,N-1) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> sz(N);
    rep(i,N) sz[i] = uv[i].size();
    ll ans = INF;
    rep(i,N) {
        vector<ll> v;
        for(auto nx: uv[i]) {
            v.push_back(sz[nx]);
        }
        sort(v.rbegin(), v.rend());
        rep(i, (int)v.size()) {
            ll rm = (v[i]-1) * (i+1);
            rm += (i+1);
            rm += 1;
            chmin(ans, N-rm);
        }
    }
    cout << ans << endl;
    return 0;
}