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
    ll N;
    cin >> N;
    if(N==0) {
        cout<<0<<endl;
        return 0;
    }
    
    ll ng = 0, ok = 1e6+1;
    while(ok-ng>1) {
        ll c = (ok+ng)/2;
        if(c*c*c >= N) ok = c;
        else ng = c;
    }
    ll mn = ok*ok*ok;
    rep(p, ok) {
        if(4*p*p*p<N) continue;        
        ll a = p;
        ll r = p, l = 0;
        while(r-l > 1) {
            ll c = (r + l)/ 2;
            ll X = c*c*c + c*c*a + c*a*a + a*a*a;
            if(X >= N) r = c;
            else l = c;
        }
        chmin(mn, r*r*r + r*r*a + r*a*a + a*a*a);
    }    
    cout << mn << endl;
    return 0;
}