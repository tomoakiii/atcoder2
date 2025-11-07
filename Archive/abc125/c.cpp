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

ll op(ll a, ll b) {
    if(b==0) return a;
    else return gcd(a, b);
}

ll e() { return 0; }

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    segtree<ll, op, e> ST(A);
    ll ans = 0;
    for(int i=0; i<N; i++) {
        ll g1 = ST.prod(0,i);
        ll g2 = ST.prod(i+1,N);
        chmax(ans, gcd(g1,g2));
    }
    cout<<ans<<endl;
    return 0;
}