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
    ll N,K;
    cin >> N >> K;
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    vector cost(N,vector<ll>(N));
    rep(i,N) rep(j,N) cin>>cost[i][j];
    ll ful = 1<<N;
    vector dp(ful, vector(N, vector<ll>(N,-INF)));
    typedef tuple<int,int,int> tpl;
    queue<tpl> que;
    rep(i,N) {
        dp[1<<i][i][i] = P[i];
        que.emplace(1<<i,i,i);
    }
    while(!que.empty()) {
        auto [S,l,r] = que.front();
        que.pop();
        rep(i,N) {
            ll nS = S|(1<<i);
            if(S==nS) continue;
            if(chmax(dp[nS][l][i], dp[S][l][r] + cost[r][i] + P[i])) {
                que.emplace(nS,l,i);
            }
        }
    }
    ll ans = -INF;
    rep(S,ful) {
        ll cnt=0;
        ll nS=S;
        while(nS) {
            cnt += (nS%2);
            nS/=2;
        }
        if(cnt != K) continue;
        rep(i,N) rep(j,N) {
            chmax(ans, dp[S][i][j] + cost[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}