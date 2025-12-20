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

void solve(){
    ll N,H;cin>>N>>H;
    ll mn=H, mx=H;
    ll ct=0;
    bool flg = true;
    rep(k,N) {
        ll t,l,u; cin>>t>>l>>u;
        ll dt = t-ct;
        ll mn2 = INF, mx2=-1;

        if(mx <= l) {
            if(l<=mx+dt) {
                chmin(mn2, l); chmax(mx2, min(mx+dt, u));
            } else {
                flg = false;
            }
        } else if (mn >= u) {
            if(mn-dt <= u) {
                chmin(mn2, max(l, mn-dt)); chmax(mx2, u);
            } else {
                flg = false;
            }
        } else {
            chmin(mn2, max(l, mn-dt)); chmax(mx2, min(mx+dt, u));
        }
        mn = mn2;
        mx = mx2;
        ct = t;
    }
    if(flg) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}


int main(){
    int T; cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}