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
    deque<int> que;
    ll Q;
    cin >> Q;
    while(Q--) {
        int t;
        cin >> t;
        if (t==1) {
            int x;
            cin >> x;
            que.push_back(x);
        } else {
            int q = que.front();
            que.pop_front();
            cout << q << endl;
        }
    }
    return 0;
}