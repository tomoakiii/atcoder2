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
    ll N, Q;
    cin >> N >> Q;
    map<pair<ll, ll>, bool> uv;
    while(Q--) {
        ll t, a, b;        
        cin >> t >> a >> b;
        a--, b--;
        if(t == 1) {
            uv[{a,b}] = true;
        } else if(t == 2) {
            uv[{a,b}] = false;
        }
        else {
            if ((uv.count({a,b}) == 0 || uv[{a,b}] == false) ||
               (uv.count({b,a}) == 0 || uv[{b,a}] == false) ) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    return 0;
}