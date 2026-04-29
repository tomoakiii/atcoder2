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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll full=1ll<<N;
    vector dp(full, vector<ll>(N,INF));
    dp[1][0]=0;
    rep(S,full){
        rep(from,N) {
            if(!(S>>from & 1)) continue;
            rep(to,N) {
                if(S>>to & 1) continue;
                ll nx=S|(1ll<<to);
                chmin(dp[nx][to], dp[S][from] + abs(from-to)*abs(A[from]-A[to]));
            }
        }
    }
    ll ans=INF;
    rep(i,N) {
        chmin(ans, dp[full-1][i]);
    }
    cout<<ans<<endl;
    return 0;
}