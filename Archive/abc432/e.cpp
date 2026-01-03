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
ll op(ll a, ll b) {return a+b;}
ll e() {return 0;}

int main(){
    ll N,Q;
    cin >> N >> Q;
    ll M = 5e5 + 10;
    vector<ll> val(M), cnt(M);
    vector<ll> A(N);
    rep(i,N) {
        ll a; cin>>A[i];
        a = A[i];
        val[a] += a;
        cnt[a]++;
    }
    segtree<ll,op,e> seg_val(val);
    segtree<ll,op,e> seg_cnt(cnt);

    while(Q--){
        int query; cin>>query;
        if(query == 1) {
            ll i,y; cin>>i>>y; i--;
            ll x = A[i];
            seg_val.set(x, seg_val.get(x) - x);
            seg_val.set(y, seg_val.get(y) + y);
            seg_cnt.set(x, seg_cnt.get(x) - 1);
            seg_cnt.set(y, seg_cnt.get(y) + 1);
            A[i] = y;
        } else {
            ll l,r; cin>>l>>r;
            if(l >= r) {
                cout << l * N << endl;
                continue;
            }
            ll ans = seg_val.prod(l, r);
            ans += seg_cnt.prod(0,l) * l;
            ans += seg_cnt.prod(r,M) * r;
            cout << ans  << endl;
        }
    }
    return 0;
}