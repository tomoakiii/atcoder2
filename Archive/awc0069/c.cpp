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
    ll N,K;
    cin >> N >> K;
    string T; cin>>T;
    vector<ll> v(N);
    rep(i,N)v[i]=T[i]-'0';
    lazy_segtree<S, op, e, F, mapping, composition, id> LS(v);


    ll ans=0;
    rep(i,N-K+1){
        auto p=LS.get(i);
        p%=2;
        if(p==0) {
            LS.apply(i,i+K,1);
            ans++;
        }
    }
    rep(i,N){
        auto p=LS.get(i);
        p%=2;
        if(p==0){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;

    return 0;
}