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
    ll N,K,Q;
    cin >> N >> K >> Q;
    vector<tuple<ll,bool,int,ll,ll>> v;
    vector<ll> D(N);
    rep(i,N) {
        ll d; cin>>d;
        v.push_back(make_tuple(d,false,i,-1,-1));
    }
    rep(i,Q){
        ll l,r,t; cin>>l>>r>>t;
        l--,r--;
        v.push_back(make_tuple(t,true,i,l,r));
    }
    sort(v.begin(),v.end());
    fenwick_tree<ll> FT(N);
    vector<ll> ans(Q,-1);
    for(auto [d, flg, i, l, r]:v){
        if(flg){
            ll sm=FT.sum(l,r+1);
            if(sm<=K) ans[i]=sm;

        }else{
            FT.add(i,1);
        }
    }
    for(auto a:ans)cout<<a<<endl;
    return 0;
}