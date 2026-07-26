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
    ll N,K,D;
    cin >> N >> K >> D;
    vector<ll> A(N+1);
    rep(i,N) cin >> A[i+1];
    rep(i,N){
        A[i+1] += A[i];
    }
    ll ans = -INF;
    rep(i,N+1){
        if(i-K<D && D<=i && i-K>=0) chmax(ans, A[i]-A[i-K]);
    }
    cout << ans << endl;
    return 0;
}