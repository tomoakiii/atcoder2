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
    ll N, M;
    cin >> N >> M;
    vector<ll> S(N), C(N);
    vector<double> P(N);
    rep(i,N) {
        ll s, c, p;
        cin >> S[i] >> C[i] >> P[i];        
    }
    vector dp(M+1, vector<double>(1<<N, 0));    
    
    for(int q=1; q<=M; q++) {
        rep(k, 1<<N) {
            rep(i,N){            
                if(k & 1<<i) continue;
                if(q < C[i]) continue;                
                chmax(dp[q][k], P[i]/100.*(S[i]+dp[q-C[i]][k|1<<i]) + (100.-P[i])/100.*dp[q-C[i]][k]);
            }
        }
    }

    printf("%.10f\n", dp[M][0]);
    return 0;
}