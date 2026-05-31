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
    ll N,M,Q,K;
    cin >> N>>M>>Q>>K;
    vector<tuple<int,ll,ll,int,int>>vt(M+Q);
    rep(i,M) {
        ll s,d; cin>>s>>d; s--;
        vt[i] = make_tuple(d,1,s,0,0);
    }
    rep(i,Q) {
        ll l,r,t; cin>>l>>r>>t; l--,r--;
        vt[i+M] = make_tuple(t,0,l,r,i);
    }
    fenwick_tree<ll> FT(N);
    sort(vt.rbegin(),vt.rend());
    vector<ll> ans(Q);
    for(auto [d,q,x,y,i] : vt) {
        if(q==1) {
            FT.add(x,1);
        } else {
            ans[i] = max(FT.sum(x,y+1)-K,0ll);
        }
    }
    for(auto a:ans)cout<<a<<endl;
    return 0;
}