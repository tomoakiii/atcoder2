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
    ll N, R;    
    cin >> N >> R;
    rep(i,N) {
        ll d, a;
        cin >>d >> a;
        ll l, r;
        if(d==1) {
            l=1600;
            r=2799;
        }else {
            l=1200;
            r=2399;
        }
        if(l<=R && R<=r) {
            R+=a;
        }
    }
    cout << R << endl;
    return 0;
}