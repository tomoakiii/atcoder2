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


struct S {
    bool ok = true;
    ll val; // -1 は「-1しか含まれていない」を表す
};

S op(S a, S b) {
    if (!a.ok || !b.ok) return {false, -1};
    if (a.val == -1) return b;
    if (b.val == -1) return a;
    if (a.val == b.val) return a;
    return {false, -1};
}

S e() {
    return {true, -1};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];

    vector<S> init(N);
    rep(i,N){
        init[i].val = A[i];
    }
    segtree<S, op, e> seg(init);

    while(Q--){
        int query; cin>>query;
        if(query==1){
            int p; ll x; cin>>p>>x; p--;
            S a; a.val = x;
            seg.set(p, a);
        } else {
            bool flg = true;
            int l,r; cin>>l>>r; l--,r--;
            auto ret = seg.prod(l,r+1);
            if(ret.ok) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
    }
    return 0;
}