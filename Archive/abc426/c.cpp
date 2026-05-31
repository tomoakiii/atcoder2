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
typedef pair<int,int> pii;
int main(){
    ll N,Q;
    cin >> N >> Q;
    priority_queue<pii, vector<pii>, greater<pii>> que;
    rep(i,N) que.push({i+1, 1});
    while(Q--) {
        int X, Y; cin>>X>>Y;
        int cnt = 0;
        while(!que.empty()) {
            auto [x, nm] = que.top();
            if(x <= X) {
                que.pop();
                cnt+=nm;
            } else {
                break;
            }
        }
        cout<<cnt<<endl;
        que.push({Y, cnt});
    }
    return 0;
}