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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), B(N);    
    rep(i,N) cin>>A[i]>>B[i];
    ll ans = INF;
    ll sm = 0;
    ll x = 0;

    for(ll i=0; i<N; i++) {
        sm += A[i] + B[i];
        x++;
        if(X - x < 0) break;
        chmin(ans, sm + (X-x) * B[i]);
    }
    cout << ans << endl;
    return 0;
}