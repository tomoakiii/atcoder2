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
    ll N,M,X;
    cin >> N >> M >> X;
    vector<ll> A(N+1);
    rep(i,M) {
        ll a; cin>>a;
        A[a] = 1;
    }
    ll ans = INF;
    ll s = 0;
    rep(i, X) {
        s += A[i];
    }
    chmin(ans,s);
    s = 0;
    for(int i=X; i<N+1; i++) {
        s+=A[i];
    }
    chmin(ans,s);
    cout<<ans<<endl;
    return 0;
}