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
    deque<int> que;
    while(Q--) {
        int k;
        cin >> k;
        if(k==1) {
            int x;
            cin >> x;
            que.push_front(x);
        } else {
            int x = que.front();
            cout << x << endl;
            que.pop_front();
        }
    }
    return 0;
}