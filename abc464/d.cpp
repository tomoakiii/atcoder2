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


void solve(){
    ll N; string S;
    cin>>N>>S;
    vector<ll> X(N);
    vector<ll> Y(N-1);
    rep(i,N) cin>>X[i];
    rep(i,N-1) cin>>Y[i];

    vector dp(N,vector<ll>(2,-INF));
    if(S[0]=='S') {
        dp[0][1]=0;
        dp[0][0]=-X[0];
    } else {
        dp[0][0]=0;
        dp[0][1]=-X[0];
    }
    for(int i=1;i<N;i++){
        if(S[i]=='S') {
            chmax(dp[i][1], dp[i-1][1]);
            chmax(dp[i][1], dp[i-1][0]+Y[i-1]);
            chmax(dp[i][0], dp[i-1][0]-X[i]);
            chmax(dp[i][0], dp[i-1][1]-X[i]);
        } else {
            chmax(dp[i][1], dp[i-1][1]-X[i]);
            chmax(dp[i][1], dp[i-1][0]+Y[i-1]-X[i]);
            chmax(dp[i][0], dp[i-1][0]);
            chmax(dp[i][0], dp[i-1][1]);
        }
    }
    cout << max(dp[N-1][0],dp[N-1][1]) <<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    rep(i,N){
        solve();
    }
    return 0;
}