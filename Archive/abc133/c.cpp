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
    ll L,R;
    cin >> L >> R;
    ll dr = R-L;
    if(dr > 5000) dr=5000;
    L %= 2019;
    R = L + dr;
    ll ans = INF;
    for(ll l = L; l <= R; l++) {
        for(ll r = l+1; r <= R; r++) {
            //printf("debug: %lld, %lld\n",l,r);
            chmin(ans, (l*r)%2019);
        }
    }
    cout<<ans<<endl;
    return 0;
}