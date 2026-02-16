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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll Q;
    cin>>Q;
    map<string,ll> mp;
    while(Q--) {
        int q; cin>>q;
        if(q==1) {
            string x; ll y; cin>>x>>y;
            mp[x] = y;
        } else if(q==2) {
            string x; cin>>x;
            cout << mp[x] << endl;
        } else {
            // que.pop();
        }
    }

    return 0;
}