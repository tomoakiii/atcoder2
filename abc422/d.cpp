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
    ll N, K; cin>>N>>K;
    vector V(N+1, vector<ll>{});
    V[0].push_back(K);
    ll u = 0;
    rep(i,N) {
        ll mx = 0, mn = INF;
        rep(k, V[i].size()) {
            ll t = V[i][k] / 2, t2 = V[i][k] - t;
            V[i+1].push_back(t);
            V[i+1].push_back(t2);
            chmax(mx, max(t, t2));
            chmin(mn, min(t, t2));
        }
        chmax(u, mx-mn);
    }
    cout << u << endl;
    for(auto v: V[N]) cout << v << " ";
    cout << endl;
    return 0;
}