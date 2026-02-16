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
    ll N,K;
    cin >> N >> K;
    vector C(N, vector<ll>(N));
    rep(i,N) rep(j,N) cin>>C[i][j];
    vector dp(N, vector(N, vector<ll>(1e5,INF));
    rep(i,N) rep(j,N) dp[i][j][1] = C[i][j];
    for(ll k=1; k*k<=1e9; k++) {
        rep(i,N) {
            rep(j,N) {
                rep(l,N) {
                    chmin(dp[i][j][k], d[i][l][k-1]
                }

            }
        }
    }


    return 0;
}