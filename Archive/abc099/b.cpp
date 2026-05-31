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
    ll a,b; cin>> a >> b;
    ll x=1;
    rep(i,100000) {
        ll sx = (x*(x+1))/2;
        x++;
        ll sy = (x*(x+1))/2;
        ll d = sy - sx;
        if(d == b-a) {
            cout<<sy-b<<endl;
            return 0;
        }
    }
    return 0;
}