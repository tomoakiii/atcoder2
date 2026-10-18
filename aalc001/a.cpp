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


ll op(ll a, ll b) { return min(a, b); }
ll e() { return INF; }
bool f(ll v) { return 0; }

int main() {
    ll N,Q; cin>>N>>Q;
    vector<ll>A(N);
    rep(i,N)cin>>A[i];
    segtree<ll, op, e> seg(A);
    while(Q--){
        int op; cin>>op;
        if(op==1){
            int i; ll x; cin>>i>>x; i--;
            seg.set(i,x);
        } else {
            int l,r; cin>>l>>r; l--;
            cout<<seg.prod(l,r)<<endl;
        }
    }
}
