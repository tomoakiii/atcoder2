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
    vector<ll> A(N, 0);
    rep(i,N) cin>>A[i];
    vector<ll> B(N+1, 0);
    rep(i, N) {
        B[i+1] = B[i] + A[i/2];
    }

    vector dp<N, vector<N>>;
    for(int i=1; i<N; i++) {
        rep (j, N) {
            dp[i][j] = B[j]
        }
    }

    cout << sm << endl;
    return 0;
}