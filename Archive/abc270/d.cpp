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
typedef pair<int,int> pii;
int main(){
    ll N, K;
    cin >> N >> K;
    vector<int> A(K);
    rep(i,K) cin>>A[i];
    /*
    vector dp(2, vector<int>(N+1, -1));
    rep(i,N+1) dp[1][i] = INFi;
    dp[0][0] = 0; dp[1][0] = 0;
    for(int i=1; i<=N; i++) {
        int mn = INFi;
        int Aoki;
        rep(j, K) {
            if(i<A[j]) continue;
            chmax(dp[0][i], dp[1][i-A[j]] + A[j]);            
        }
        rep(j, K) {
            if(i<A[j]) continue;
            chmin(dp[1][i], dp[0][i-A[j]]);
        }        
    }
    cout << dp[0][N] << endl;
    */


    vector stone(N+1, vector<int>(2, -1));
    stone[0][0] = 0;
    stone[0][1] = 0;
    auto func = [&](auto func, int rem, int turn) -> void {
        int opp = (turn==1)?0:1;
        rep(i,K) {
            if(rem < A[i]) continue;
            if(stone[rem-A[i]][opp] == -1) {
                func(func, rem-A[i], opp);                
            }            
            chmax(stone[rem][turn], A[i] + (rem - A[i] - stone[rem-A[i]][opp]));
        }
    };
    func(func, N, 0);
    cout << stone[N][0] << endl;

    return 0;
}