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
    ll N,M;
    cin >> N >> M;
    vector B(M, vector<ll>(N));
    vector<ll> A(M);
    rep(i,M) {
        ll b; cin>>A[i]>>b;
        rep(j,b) {
            ll c; cin>>c; c--;
            B[i][c] = 1;
        }
    }
    ll Q = 1<<N;
    vector<ll> dp(Q+1, INF);
    dp[0] = 0;
    rep(i,M) {
        ll buy = 0;        
        rep(j,N) {
            if(B[i][j]) buy |= 1<<j;
        }
        rep(k,Q){                         
            chmin(dp[buy | k], dp[k] + A[i]);            
        }
    }
    if(dp[Q-1]==INF) cout<<-1<<endl;
    else cout<<dp[Q-1]<<endl;

    return 0;
}