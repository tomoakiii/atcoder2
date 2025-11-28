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
typedef modint1000000007 mint;


// N=5000以下で使うこと
vector<vector<mint>> Combination(int MAX_N) {    
    vector comb(MAX_N+1, vector<mint>(MAX_N));
    for (int i = 0; i <= MAX_N; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
        }
    }
    return comb;
}


int main(){
    ll N,K; cin>>N>>K;
    vector dp(N-K+1, vector<mint>(N-K+1)); // x個のボールを0個を許してy通りに分割する方法
    auto comb = Combination(N);
    ll p = K, q = N-K;
    for(ll i=1; i<=K; i++) {        
        mint red = comb[q+1][i];
        mint blue = comb[p-1][i-1];
        mint ans = red * blue;
        cout<<ans.val()<<endl;
    }
    return 0;
}