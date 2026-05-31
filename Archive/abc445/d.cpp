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
    ll H,W,N;
    cin >> H>>W>>N;
    set<pair<ll,int>> hst,wst;
    vector<pair<ll,ll>> hw(N);
    rep(i,N) {
        ll h,w; cin>>h>>w;
        hst.insert({-h,i});
        wst.insert({-w,i});
        hw[i] = {h,w};
    }
    vector<pair<ll,ll>> ans(N);
    while(H>0 && W>0) {
        auto [h,i0] = *hst.begin();
        auto [w,i1] = *wst.begin();
        h *= -1;
        w *= -1;
        if(H == h) {
            auto [ht,wt] = hw[i0];
            ans[i0] = {1, W-wt+1};
            hst.erase({-ht,i0});
            wst.erase({-wt,i0});
            W -= wt;
        } else {
            auto [ht,wt] = hw[i1];
            ans[i1] = {H-ht+1, 1};
            hst.erase({-ht,i1});
            wst.erase({-wt,i1});
            H -= ht;
        }
    }
    for(auto [h,w]:ans) cout<<h<<" "<<w<<endl;
    return 0;
}