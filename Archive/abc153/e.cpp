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
    ll H,N;
    cin >> H >> N;
    vector<ll> A(N), B(N);
    rep(i,N) cin >> A[i] >> B[i];
    vector<ll> dp(H+1, INF);
    dp[H] = 0;
    for(ll h=H; h>0; h--) {
        rep(i,N) {
            for(ll k=A[i]; k<=A[i]; k++){
                if(h - A[i] <= 0) {
                    chmin(dp[0], dp[h] + B[i]);
                } else {
                    chmin(dp[h - A[i]], dp[h] + B[i]);
                }
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}