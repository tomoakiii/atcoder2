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
    ll N, K, X;
    cin>>N>>K>>X;

    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.rbegin(), A.rend());
    rep(i,N-K) {
        A[i] = 0;
    }
    ll ans = 0;
    rep(i,N) {
        ans += A[i];
        if(ans >= X) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}