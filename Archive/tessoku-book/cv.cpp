#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef long double ld;
typedef long long ll;
const ld INF = 10000000;
const ld hINF = 5000000;

int main(){
    ll N; cin>>N;
    vector<ll> X(N),Y(N);
    rep(i,N) cin>>X[i]>>Y[i];

    auto distance = [&](int i, int j)->ld{
        ld d = (X[i]-X[j]) * (X[i]-X[j]) + (Y[i]-Y[j]) * (Y[i]-Y[j]);
        return sqrtl(d);
    };

    vector dist(N, vector<ld>(N));
    rep(i,N) rep(j,N) dist[i][j] = distance(i,j);

    ld ans = INF;
    deque<int> ord(N);
    rep(i,N) ord[i] = i;
    rep(st, N) {
        vector dp(1ll<<N, vector<ld>(N,INF));
        dp[0][0] = 0;
        dp[1][0] = 0;
        for(ll k=1; k < (1ll<<N); k++) {
            rep(last,N) {
                if(dp[k][last] > hINF) continue;
                for(int i=1; i<N; i++) {
                    if(k>>i & 1) continue;
                    chmin(dp[k|(1ll<<i)][i], dp[k][last] + dist[ord[i]][ord[last]]);
                }
            }
        }

        rep(last,N) {
            chmin(ans, dp[(1ll<<N)-1][last] + dist[ord[last]][ord[0]]);
        }
        ord.push_back(ord[0]);
        ord.pop_front();
    }
    printf("%.30Lf\n", ans);
    return 0;
}