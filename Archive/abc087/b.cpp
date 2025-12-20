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
    ll A,B,C,X;
    cin >>A>>B>>C>>X;
    ll ans = 0;
    rep(a, A+1) rep(b, B+1) rep(c, C+1) {
        ll sm = 500*a + 100*b + 50*c;
        if(sm == X) ans++;
    }
    cout<<ans<<endl;
    return 0;
}