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
    ll N,Ma,Mb;
    cin >> N >> Ma >> Mb;
    vector dp(N*10 + 1, vector<ll>(N*10 + 1, INF));
    dp[0][0] = 0;
    rep(i,N) {
        ll a,b,c;
        cin>>a>>b>>c;
        vector dp_new = dp;
        rep(x, N*10) {
            ll na = x + a;
            if(na > N*10) break;
            rep(y, N*10) {
                ll nb = y + b;
                if(nb > N*10) break;
                chmin(dp_new[na][nb], dp[x][y] + c);
            }
        }
        swap(dp, dp_new);
    }
    ll ans = INF;
    for(ll a = 1; a <= N*10; a++) {
        for(ll b = 1; b <= N*10; b++) {
            if(b * Ma != a * Mb) continue;
            chmin(ans, dp[a][b]);
        }
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}