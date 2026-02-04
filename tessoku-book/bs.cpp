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


int main() {
    int N; cin>>N;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    ll ans = 0;
    rep(i,N) ans += A[i]*B[i];
    cout << ans << endl;

}