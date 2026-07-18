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
    ll N,K;
    cin >> N >> K;
    vector<ll> T(N);
    rep(i,N) cin>>T[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(T);
    rep(i,N) {
        ll x = LS.get(i);
        if(x==0) continue;
        if(x < 0) {
            cout<<"No"<<endl;
            return 0;
        }
        if(i+K-1 >= N) {
            cout<<"No"<<endl;
            return 0;
        }
        LS.apply(i, i+K, -x);
    }
    cout<<"Yes"<<endl;
    return 0;
}