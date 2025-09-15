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
    ll X,C;
    cin >> X >> C;
    ll l = 0, r = 1E4;
    while(r-l > 1) {
        ll c = (l+r)/2;        
        ll p = c * C;
        ll c2 = c * 1000 + p; 
        if(c2 <= X) {
            l = c;
        } else {
            r = c;
        }
    }
    cout << l*1000 << endl;
    return 0;
}