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
    ll X;
    cin >> X;
    if(X==1) {
        cout<<1<<endl;
        return 0;
    }
    ll ans = 0;
    for(ll x = 2; x <= X; x++) {
        ll y = x;
        while(y*x <= X) {
            y *= x;
            chmax(ans, y);
        }
    }
    cout << ans << endl;
    return 0;
}