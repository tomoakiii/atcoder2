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
    ll H,W,Q;
    cin >> H>>W>>Q;
    int r = H, c = W;
    while(Q--) {
        int q; cin>>q;
        ll x; cin>>x;
        if(q==1) {
            cout<<x*c<<endl;
            r-=x;
        } else {
            cout << x*r << endl;
            c -= x;
        }
    }
    return 0;
}