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
    auto R=A, L=A;
    rep(i,N-1) chmax(L[i+1], L[i]);
    for(int i=N-1;i>=1;i--) chmax(R[i-1], R[i]);
    ll D; cin>>D;
    while(D--) {
        ll l, r; cin>>l>>r; l--,r--;
        ll ans = 0;
        if(l>0) chmax(ans, L[l-1]);
        if(r<N-1) chmax(ans, R[r+1]);
        cout << ans << endl;
    }
    return 0;
}