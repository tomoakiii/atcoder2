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
    priority_queue<ll,vector<ll>,greater<ll>> que;
    while(Q--) {
        int q; cin>>q;
        if(q==1) {
            ll s; cin>>s;
            que.push(s);
        } else if(q==2) {
            cout << que.top() << endl;
        } else {
            que.pop();
        }
    }

    return 0;
}