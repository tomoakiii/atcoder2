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
    deque<int> dq;
    while(Q--){
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            dq.emplace_front(x);
        } else if (t == 2) {
            dq.emplace_back(x);
        } else {
            cout << dq[x-1] << endl;
        }
    }

    return 0;
}