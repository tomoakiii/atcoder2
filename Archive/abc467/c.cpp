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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N),B(N-1);
    rep(i,N) cin>>A[i];
    rep(i,N-1) cin>>B[i];
    vector<ll> dp(2,1);
    dp[A[0]%2] = 0;
    rep(i,N-1){
        vector dp2(2,INF);
        bool flg = B[i];
        bool non = !flg;
        if( A[i+1]%2 == 0) {
            if(B[i] % 2 == 0) {
                chmin(dp2[0], dp[0]); // ev -> ev
                chmin(dp2[1], dp[1] + 1);
            } else {
                chmin(dp2[1], dp[0]+1); // ev -> ev
                chmin(dp2[0], dp[1]);
            }
        } else {
            if(B[i] % 2 == 0) {
                chmin(dp2[0], dp[0] + 1); // ev -> ev
                chmin(dp2[1], dp[1]);
            } else {
                chmin(dp2[1], dp[0]); // ev -> ev
                chmin(dp2[0], dp[1]+1);
            }
        }
        swap(dp, dp2);
    }
    cout<<min(dp[0], dp[1])<<endl;
    return 0;
}