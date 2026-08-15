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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    vector dp(N+1, vector<ll>(M+1));
    rep(i,N) rep(j,M) {
        ll a; cin>>a;
        dp[i][j]+=a;
        chmax(dp[i+1][j],dp[i][j]);
        chmax(dp[i][j+1],dp[i][j]);
    }
    cout<<dp[N-1][M-1]<<endl;
    return 0;
}