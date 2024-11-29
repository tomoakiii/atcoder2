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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i]--;
    }

    vector dp(N+1, vector<pair<int,bool>>(20, true));
    rep(i,N) {
            int p = A[i];
            if(!dp[i][p].second) {
                dp[i+1][p].first = dp[i][p].first + 2;
                dp[i+1][p].second = true;
            } else {
                dp[i+1][p].second = false;
            }
            rep(j,20){
            if (!dp[i+1][j].second) {
                dp[i+1][j] = dp[i+1][j].first + 2;
            }
        } 
    }
    return 0;
}