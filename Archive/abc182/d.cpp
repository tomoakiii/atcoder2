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
    rep(i,N) cin>>A[i];
    ll sm = 0;
    ll mx = max(0ll,A[0]);
    ll ans = -INF;
    rep(i,N-1) {
        A[i+1] += A[i];
        chmax(mx, A[i+1]);
        chmax(ans, sm + mx);
        sm += A[i];
    }
    chmax(ans, sm + mx);
    cout << ans << endl;
    return 0;
}