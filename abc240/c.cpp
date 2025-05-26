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
    ll N, X;
    cin>>N>>X;
    vector<int> A(N), B(N);
    rep(i,N) cin>>A[i]>>B[i];
    vector<int> dp(X+1);
    dp[0] = 1;
    rep(i,N) {
        vector<int> dp_n(X+1);
        rep(j,X) {
            if(dp[j] == 1 && j+A[i] <= X) {
                dp_n[j+A[i]] = 1;
            }
            if(dp[j] == 1 && j+B[i] <= X) {
                dp_n[j+B[i]] = 1;
            }
        }
        swap(dp_n, dp);
    }
    if(dp[X]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}