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
    ll N, M;
    cin >> N >> M;
    ll S,T; cin>>S>>T; S--,T--;
    pair<ll,ll> st = {S/N, S%N};
    pair<ll,ll> ed = {T/N, T%N};
    vector<pair<ll,ll>> P(M);
    rep(i,M) {
        ll p; cin>>p; p--;
        P[i] = {p/N,p%N};
    }
    vector dist(M, vector<ll>(M,INF));
    auto func = [&](pair<ll,ll> x, pair<ll,ll> y) -> ll{
        return abs(x.first-y.first) + abs(x.second-y.second);
    };
    if(M==0) {
        cout << func(st,ed) << endl;
        return 0;
    }
    rep(i,M) {
        rep(j,M) {
            dist[i][j] = dist[j][i] = func(P[i],P[j]);
        }
    }
    vector dp(1ll<<M, vector<ll>(M,INF));
    rep(i,M) {
        dp[1<<i][i] = func(st, P[i]);
    }
    for(ll k = 1; k < 1ll<<M; k++) {
        rep(from,M) {
            if((k>>from & 1) == 0) continue;
            rep(to,M) {
                chmin(dp[k | (1ll<<to)][to], dp[k][from] + func(P[from], P[to]));
            }
        }
    }
    ll ans = INF;
    ll full = 1<<M;
    full--;
    rep(i,M) {
        chmin(ans, dp[full][i] + func(P[i],ed));
    }
    cout<<ans<<endl;
    return 0;
}