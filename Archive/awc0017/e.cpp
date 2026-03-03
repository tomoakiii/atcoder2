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
typedef pair<ll, pair<ll,int>> pli;
int main(){
    ll N;
    cin >> N;
    vector<ll> X(N),Y(N);
    rep(i,N) cin>>X[i]>>Y[i];
    vector dist(N, vector<ll>(N));
    rep(i,N) for(int j=i+1;j<N;j++) {
        ll dx=X[i]-X[j];
        ll dy=Y[i]-Y[j];
        dist[i][j]=dist[j][i]=dx*dx+dy*dy;
    }
    ll F=1ll<<N;
    ll ans = INF;
    vector dp(F, vector<ll>(N,INF));
    priority_queue<pli, vector<pli>, greater<pli>> que;
    dp[1][0]=0;
    que.push({0, {1, 0}});
    while(!que.empty()){
        auto [v,ki] = que.top();
        auto [k,i] = ki;
        que.pop();
        if(dp[k][i] < v) continue;
        rep(j,N) {
            if(k>>j & 1) continue;
            ll nk = k|(1ll<<j);
            if(chmin(dp[nk][j], dp[k][i]+dist[i][j])) {
                que.push({dp[nk][j], {nk,j}});
            }
        }
    }
    for(int i=1; i<N; i++) chmin(ans, dp[F-1][i] + dist[i][0]);
    cout<<ans<<endl;
    return 0;
}