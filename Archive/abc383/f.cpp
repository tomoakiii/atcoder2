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
typedef tuple<ll, ll, ll> tplll;

int main(){
    ll N, X, K;
    cin >> N >> X >> K;
    vector<tplll> CPU(N);
    rep(i,N) {
        ll p, u, c;
        cin>>p>>u>>c;
        tplll t = {c, p, u};
        CPU[i] = t;
    }
    sort(CPU.begin(), CPU.end());
    vector dp(X+1, vector<ll>(2, -INF));
    dp[0][0] = 0;
    ll lscm = 0;
    ll lsc = -1;
    rep(i,N){
        vector nw(X+1, vector<ll>(2, -INF));
        auto [c, p, u] = CPU[i];
        if(c != lsc) {
            rep(j, X+1) {
                chmax(nw[j][0], max(dp[j][0], dp[j][1]));
                if(p + j > X) continue;
                chmax(nw[j+p][1], nw[j][0] + K + u);
            }
        } else {
            rep(j, X+1) {
                chmax(nw[j][1], dp[j][1]);
                chmax(nw[j][0], dp[j][0]);
                if(p + j > X) continue;
                chmax(nw[j+p][1], max(dp[j][0] + K + u, dp[j][1] + u));
            }
        }
        swap(dp, nw);
        lsc = c;
    }
    ll ans=0;
    rep(j, X+1){
        rep(k,2) {
            chmax(ans, dp[j][k]);
        }
    }
    cout << ans << endl;
    return 0;
}