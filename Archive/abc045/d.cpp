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
    cin >> H >> W >> N;
    set<pair<ll,ll>> cb, bl;
    while(N--) {
        ll a, b; cin>>a>>b; a--,b--;
        bl.insert({a,b});
        rep(i,3)rep(j,3){
            if(a-i>=0 && b-j>=0 && a-i+2<H && b-j+2<W)cb.insert({a-i, b-j});
        }
    }
    vector<ll> ans(10);
    for(auto [cy,cx] :cb) {
        int sm = 0;
        rep(i,3)rep(j,3){
            if(bl.contains({cy+i,cx+j})) sm++;
        }
        ans[sm]++;
    }
    ll tot = 0;
    rep(i,9) tot += ans[i+1];
    ans[0] = (H-2)*(W-2) - tot;
    for(auto a:ans) cout<<a<<endl;
    return 0;
}