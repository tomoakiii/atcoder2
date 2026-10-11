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
using F = ll;
S op(S l, S r) { return max(l, r); }
S e() { return 0; }
S mapping(F l, S r) { return r += l; }
F composition(F l, F r) { return l + r; }
F id() { return 0; }




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<set<pair<ll,ll>>> LR(Q);
    rep(i,Q){
        LR[i].insert({-INF,-INF});
        LR[i].insert({INF,INF});
    }
    rep(i,Q){
        ll l,r,x; cin>>l>>r>>x; x--;
        l--,r--;
        ll mn = l, mx = r;
        while(true){
            auto it = LR[x].upper_bound({r,INF});
            it--;
            auto [pl,pr] = *it;
            if(pr>=l){
                chmin(mn, pl);
                chmax(mx, pr);
                LR[x].erase(it);
            } else {
                break;
            }
        }
        LR[x].insert({mn,mx});
    }

    vector<S> A(N);
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(A);
    rep(i,Q){
        for(auto [l,r]:LR[i]){
            if(l==INF || l==-INF)continue;
            LS.apply(l,r+1,1);
        }
    }
    rep(i,N){
        cout << LS.get(i) << " \n"[i==N-1];
    }
    return 0;
}