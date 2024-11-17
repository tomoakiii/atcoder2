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
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll day = 0;
    while(Q--){
        int x;
        cin >> x;
        if (x == 1) {
            pq.push(day);
        } else if (x == 2) {
            ll T;
            cin >> T;
            day += T;
        } else {
            ll cnt = 0;
            ll H;
            cin >> H;
            while(!pq.empty()) {
                auto q = pq.top();          
                if (day - q >= H) {
                    cnt++;
                    pq.pop();
                } else {
                    break;
                }
            }
            cout << cnt << endl;
        }

    }
    return 0;
}