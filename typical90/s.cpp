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
typedef pair<ll, int> pli;
int main(){
    ll N;
    cin >> N;
    N*=2;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector dp(N, vector<ll>(N, INF));
    ll ans = 0;

    rep(i,N-1) {
        dp[i][i+1] = abs(A[i+1] - A[i]);
    }
    for(int k=3; k<N; k+=2) {
        rep(i,N) {
            if(i+k >= N) break;
            chmin(dp[i][i+k], dp[i+1][i+k-1]+abs(A[i]-A[i+k]));            
            for(int j=i+1; j<i+k; j+=2) {
                chmin(dp[i][i+k], dp[i][j]+dp[j+1][i+k]);
            }
        }
    }
    cout << dp[0][N-1] << endl;
    return 0;
}