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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> T(N+1);
    rep(i,N) {
        cin>>T[i+1]; T[i+1]--;
    }
    vector C(N+2, vector<ll>(N+2, INF));
    rep(i,N+1){
        for(int j=i+1;j<N+2;j++)cin>>C[i][j];
    }
    ll ful = 1ll<<M;
    vector dp(ful, vector(K+1, vector<ll>(N+2,INF)));
    dp[0][0][0] = 0;
    rep(i,N+1){
        rep(k,K+1){
            ll nk = min(k+1, K);
            rep(S,ful){
                if(dp[S][k][i] == INF) continue;
                for(int j=1;j<=N;j++){
                    ll t = T[j];
                    ll S2 = S ^ (1ll<<t);
                    chmin(dp[S2][nk][j], dp[S][k][i] + C[i][j]);
                }
                chmin(dp[S][k][N+1], dp[S][k][i] + C[i][N+1]);
            }
        }
    }
    if(dp[0][K][N+1] == INF) cout<<-1<<endl;
    else cout<<dp[0][K][N+1]<<endl;
    return 0;
}