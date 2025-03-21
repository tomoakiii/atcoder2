#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<ll, ll> pll;
typedef pair<pll, int> plli;
int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    
    vector<int> A(M), B(M);
    vector<ll> C(M);
    rep(i,M) {        
        cin >> A[i] >> B[i] >> C[i];
        A[i]--, B[i]--;        
    }
    vector<ll> E(K);    
    rep(i,K) {
        cin>>E[i];
        E[i]--;        
    }
    
    vector<ll> dp(N, INF);
    dp[0] = 0;
    rep(i, K) {        
        int e = E[i];
        chmin(dp[B[e]], dp[A[e]] + C[e]);        
    }    
    ll ans = dp[N-1];
    if(ans >= INF) ans = -1;
    cout << ans << endl;
    return 0;
}