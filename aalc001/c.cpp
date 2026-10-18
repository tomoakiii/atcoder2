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
using S = ll;
S op(S l, S r) { return l+r; }
S e() { return 0; }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    segtree<S, op, e> seg(A);
    while(Q--){
        int op; cin>>op;
        
        if(op==1){
            int i;
            ll x; cin>>i>>x; i--;
            seg.set(i,x);
        } else if(op == 2){
            ll target;
            int l; cin>>l>>target; l--;
            auto fnc = [&](ll x)->bool{
                return x<target;
            };
            cout<<seg.max_right(l,fnc)+1<<endl;
        } else {
            ll target;
            int r; cin>>r>>target;
            auto fnc = [&](ll x)->bool{
                return x<target;
            };
            cout<<seg.min_left(r,fnc)<<endl;
        }
    }
    return 0;
}