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
using mint = modint998244353;

int main(){
    ll Q;
    cin >> Q;
    mint s = 1;
    mint d = 1;
    vector<int> si{}; 
    si.push_back(1);
    int ind=0;
    while(Q--){
        ll p, x;
        cin >> p;
        if (p == 1) {
            cin >> x;
            s = s*10 + x;
            si.push_back(x);
            d *= 10;
        } else if (p == 2) {
            s = s - d * si[ind++];
            d /= 10;
        } else {
            cout << s.val() << endl;
        }
    }

    return 0;
}