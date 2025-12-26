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
    ll N,A,B;
    cin >> N >> A >> B;
    priority_queue<ll> que;
    rep(i,N) {
        ll h; cin>>h; que.push(h);
    }
    ll th = 0;
    int cnt = 0;
    while(!que.empty()) {
        auto q = que.top();
        que.pop();
        if(q <= th) {
            cout << cnt << endl;
            return 0;
        } else {
            que.push(q-A+B);
            th += B;
            cnt++;
        }
    }
    return 0;
}