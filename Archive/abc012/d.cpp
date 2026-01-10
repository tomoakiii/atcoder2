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
    ll N,M;
    cin >> N >> M;
    vector dist(N, vector<ll>(N,INF));
    rep(i,N) dist[i][i] = 0;
    rep(i,M) {
        ll a,b,t;
        cin>>a>>b>>t; a--, b--;
        dist[a][b] = dist[b][a] = t;
    }
    rep(c,N)rep(i,N)rep(j,N) chmin(dist[i][j], dist[i][c]+dist[c][j]);
    ll ans = INF;
    rep(i,N) {
        ll mx = 0;
        rep(j,N) chmax(mx, dist[i][j]);
        chmin(ans, mx);
    }
    cout << ans << endl;
    return 0;
}