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
    ll W,H,N; cin>>W>>H>>N;
    ll xmn = W, xmx = 0, ymn = H, ymx = 0;
    rep(i,N) {
        ll x,y,a; cin>>x>>y>>a;
        if(a==1) chmax(xmx, x);
        else if(a == 2) chmin(xmn, x);
        else if(a == 3) chmax(ymx, y);
        else chmin(ymn, y);
    }
    ll dx = xmn - xmx;
    ll dy = ymn - ymx;
    if(dx <= 0 || dy <= 0) cout << 0 << endl;
    else cout << (dx * dy) << endl;
    return 0;
}