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
    int Q; cin>>Q;
    deque<ll> dq;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    while(Q--){
        int q; cin>>q;
        if(q==1) {
            ll x; cin >> x;
            dq.push_back(x);
        } else if (q == 2) {
            if(que.empty()) {
                cout<<dq.front()<<endl;
                dq.pop_front();
            } else {
                cout << que.top() << endl;
                que.pop();
            }
        } else {
            while(!dq.empty()) {
                que.push(dq.front());
                dq.pop_front();
            }
        }
    }
    return 0;
}