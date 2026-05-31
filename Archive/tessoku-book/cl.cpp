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
typedef long double ld;
int main(){
    ll N,K; cin>>N>>K;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    rep(i,N-1) A[i+1] += A[i];
    ll last = 0;
    ll ans = 0;
    rep(i,N) {
        int it = upper_bound(A.begin(), A.end(), last + K) - A.begin();
        it--;
        if(it >= i) ans += (it-i+1);
        last = A[i];
    }
    cout << ans << endl;
    return 0;
}