#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;

int main(){
    ll n, K;
    cin >> n >> K;
    if(n==1) {
        cout << 1 << endl;
        return 0;
    }
    mint N = n;
    vector P(K + 1, vector<mint>(3));
    P[0][0] = 1;
    P[0][1] = 1;
    P[0][2] = 0;
    for(int i=1; i<=K; i++) {
        P[i][0] = P[i-1][0] * N * N; // bunbo
        P[i][1] = (P[i-1][1] * (1 +  (N-1) * (N-1))) +
            (P[i-1][2] * 2); // 0th is black
        P[i][2] = P[i][0] - P[i][1]; // 0th is white        
    }
    mint sm = 0;
    for(int i=2; i<=n; i++) {
        mint I = i;
        sm = sm + I;
    }
    sm = sm * P[K][2];
    sm = sm / (N-1);
    sm = sm + P[K][1];
    sm = sm / P[K][0];
    
    cout << sm.val() << endl;
    return 0;
}