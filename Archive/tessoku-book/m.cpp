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
    ll N,K; cin>>N>>K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ans = 0;
    rep(i,N) {
        ll a = A[i];
        auto it = lower_bound(A.begin(),A.end(),a+K) - A.begin();
        if(it==N) it--;
        else if(A[it] > a+K) it--;
        if(it > i) ans += it - i;
        cerr << it-i << endl;
    }
    cout << ans << endl;
    return 0;
}