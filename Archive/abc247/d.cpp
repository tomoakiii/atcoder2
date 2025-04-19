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
    ll Q;
    cin >> Q;
    deque<pair<ll, ll>> que;
    while(Q--){
        int k;
        cin >> k;
        if(k==1) {
            ll x, c;
            cin >> x >> c;
            que.push_back({x,c});
        } else {
            ll c;
            cin >> c;            
            ll sm = 0;
            while(c > 0) {
                auto [x, q] = que.front();
                que.pop_front();
                if(q > c) {
                    sm += x * c;
                    q -= c;
                    c = 0;
                    que.push_front({x, q});
                } else {
                    sm += q * x;
                    c -= q;
                }
            }
            cout << sm << endl;
        }
    }
    return 0;
}