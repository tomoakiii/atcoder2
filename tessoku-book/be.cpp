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
typedef pair<ll, pair<int,int>> pl;
typedef modint998244353 mint;
int main(){
    ll N,Q;
    cin>>N>>Q;
    vector dp(31, vector<int>(N));
    rep(i,N) dp[0][i] = i;
    rep(i,N) {
        cin>>dp[1][i];
        dp[1][i]--;
    }
    for(int j=2; j<=30; j++) {
        rep(i,N) {
            int nx = dp[j-1][i];
            dp[j][i] = dp[j-1][nx];
        }
    }
    while(Q--) {
        int X; ll Y; cin>>X>>Y;
        X--;
        int j = 1;
        while(Y>0) {
            if(Y%2) X = dp[j][X];
            j++;
            Y/=2;
        }
        cout << X+1 << endl;
    }
    return 0;
}