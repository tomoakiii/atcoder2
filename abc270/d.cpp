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
    ll N, K;
    cin >> N >> K;
    vector<int> A(K);
    rep(i,K) cin>>A[i];
    sort(A.begin(), A.end());
    vector dp(N+1, vector<int>(2));
    dp[1][0] = 1; dp[1][1] = 1;
    for(int i=2; i<=N; i++) {
        for(int j=0; j<K; j++){
            dp[i][0] = 
        }
        
    }

    
    return 0;
}