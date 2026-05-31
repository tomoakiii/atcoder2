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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];

    vector score(N, vector<ll>(N,INF));
    rep(i,N) {
        ll mn=A[i], mx=A[i];
        score[i][i] = 0;
        for(int j=i+1; j<N; j++) {
            chmax(mx,A[j]);
            chmin(mn,A[j]);
            score[i][j] = mx-mn;
        }
    }
    ll ans=INF;
    vector dp(N+1, vector<ll>(K+1, INF));
    auto dfs = [&](auto dfs, int cur, int k, ll sm)->void{
        if(k>K) return;
        if(dp[cur][k] <= sm) return;
        dp[cur][k] = sm;
        if(cur==N) {
            if(k<K) return;
            chmin(ans,sm);
        }
        for(int nx=cur; nx<N; nx++) {
            dfs(dfs, nx+1, k+1, sm+score[cur][nx]);
        }
    };
    dfs(dfs,0,0,0);
    cout<<ans<<endl;
    return 0;
}