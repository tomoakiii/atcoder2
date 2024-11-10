#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<double> C(N);
    vector<ll> P(N);
    vector S(N, vector<double>{}); 
    vector dp(N, vector<double>(101));// i番目のルーレットでj点取る確率
    dp[0] = 0;
    for (int i=0; i<N; i++){
        cin >> C[i] >> P[i];        
        S[i].resize(P[i]);
        for (int j=0; j<P[i]; j++){
            cin >> S[i][j];
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<P[i]; j++){
            dp[i][S[i][j]] = 1/P[i];            
        }
        
    }
    
    return 0;
}

