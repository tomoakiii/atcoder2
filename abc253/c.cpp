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
    int Q;
    cin >> Q;
    map<ll, int> mp;
    ll mn = INF, mx = 0;
    while(Q--) {
        int p;
        cin >> p;
        if(p == 1) {
            ll x;
            cin >> x;
            mp[x]++;
            if(mn > x) mn = x;
            if(mx < x) mx = x;
        } else if (p == 2) {
            ll x;
            int c;
            cin >> x >> c;
            mp[x] -= min(mp[x], c);
            if(mp[x] == 0) {
                mp.erase(x);
            }
        } else {
            auto it = mp.end();
            it--;
            cout << it->first - mp.begin()->first << endl;
        }
    }
    return 0;
}