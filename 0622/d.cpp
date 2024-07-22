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
    ll N, K;
    cin >> N >> K;
    string S;
    rep(i, N-K){
        if (S[i] != '?') continue;
        if (S[i+K-1] != '?') S[i] = 'A';       
    }
    
    cout << dp[N-1][1].val() << endl;
    return 0;
}