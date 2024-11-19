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
typedef modint998244353 mint;

int main(){    
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> X(M), Y(M);
    rep(i,M) {
        cin>>X[i]>>Y[i];
        X[i]--, Y[i]--;
    }
    deque<mint> dp(N);
    dp[0] = 1;
    rep(i,K) {
        vector<mint> tmp(M);
        rep(j, M) {
            tmp[j] = dp[X[j]];
        }        
        dp.push_front(dp.back());
        dp.pop_back();
        rep(j,M){
            dp[Y[j]] += tmp[j];
        }
    }
    mint ans;
    rep(i,N) ans += dp[i];
    cout << ans.val() << endl;
    return 0;
}