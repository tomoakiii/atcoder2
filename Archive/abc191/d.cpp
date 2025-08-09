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
    double x, y, r; cin>>x>>y>>r;
    x += 1e6, y += 1e6;
    ll X = round(x*10000), Y = round(y*10000), R = round(r*10000);

    auto jdg = [&](ll a, ll b)->bool{
        ll dr = (a-X)*(a-X) + (b-Y)*(b-Y);
        return dr <= R*R;
    };
    ll ans = 0;
    ll xs = X+9999-R;
    ll rs = xs%10000;
    xs -= rs;
    rs = (X+R)%10000;
    ll xe = X+R-rs;
    for(; xs <= xe; xs+=10000) {
        ll ok = Y, ng = Y + R + 1000;
        while(ng-ok > 1) {
            ll c = (ng+ok)/2;
            if(jdg(xs,c)) ok = c;
            else ng = c;
        }
        ll y1 = ok/10000;
        ok = Y, ng = Y - R - 1000;
        while(ok-ng > 1) {
            ll c = (ng+ok)/2;
            if(jdg(xs,c)) ok = c;
            else ng = c;
        }
        ll y2 = (ok+9999)/10000;
        ans += y1-y2+1;
    }
    cout<<ans<<endl;
    return 0;
}