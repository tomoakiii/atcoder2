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
    ll N,Q;
    cin >> N >> Q;
    vector<tuple<ll,bool,ll,ll,int>> DAVTLR(N+Q);
    rep(i,N) {
        ll a,d,v; cin>>a>>d>>v;
        DAVTLR[i]=make_tuple(d,false,a*v,i,-1);
    }

    rep(i,Q){
        ll l,r,t; cin>>l>>r>>t; l--,r--;
        DAVTLR[i+N]=make_tuple(t,true,l,r,i);
    }
    vector<ll> ans(Q);
    fenwick_tree<ll> FT(N);
    sort(DAVTLR.begin(), DAVTLR.end());
    for(auto [x1,flg,x2,x3,i]:DAVTLR){
        if(!flg){
            FT.add(x3,x2);
        } else {
            ll sm=FT.sum(x2,x3+1);
            ans[i]=sm;
        }
    }
    for(auto a:ans)cout<<a<<endl;
    return 0;
}