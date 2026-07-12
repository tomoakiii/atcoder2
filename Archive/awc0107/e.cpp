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

/* ---------------------------------------
 [How to]
 Get max value in range l to r
 LS.prod(l,r+1);

 Add x in range l to r
 LS.apply(l,r+1,x);
--------------------------------------- */
typedef pair<ll,int> S;
using F = ll;
S op(S l, S r) {
    if(r.first < l.first) return r;
    else return l;
}
S e() { return {INF,INF}; }
S mapping(F l, S r) {
    r.first += l;
    return r;
}
F composition(F l, F r) { return l + r; }
F id() { return 0; }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T,N,D,Q;
    cin >> T >> N >> D >> Q;
    ll M = T-D+1;
    vector<S> vec(M,{0,0});
    rep(i,M) vec[i].second = i;
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(vec);
    vector<pair<ll,ll>> LR(N, {-1,-1});
    auto get = [&](int i, ll l, ll r)->void{
        ll d = r-l;
        if(D<d) {
            LR[i] = {-1,-1};
            return;
        }
        ll rm = D-d;
        ll st = l-rm;
        if(st<0) st=0;
        ll ed = l+1;
        if(ed > M) ed=M;
        LS.apply(st, ed, 1);
        LR[i] = {st, ed};
    };
    rep(i,N) {
        ll l, r; cin>>l>>r;
        get(i,l,r);
    }

    auto debug = [&]()->void{
        rep(i,M) {
            cerr << LS.get(i).first << " " << LS.get(i).second << " \n"[i==M-1];
        }
    };

    while(Q--){
        int query; cin>>query;
        if(query==1) {
            int i; ll l,r;
            cin>>i>>l>>r;
            i--;
            if(LR[i].first != -1) LS.apply(LR[i].first, LR[i].second, -1);
            get(i,l,r);
        } else {
            // debug();
            auto gt = LS.all_prod();
            cout << gt.second << " " << gt.first << endl;
        }
    }
    return 0;
}