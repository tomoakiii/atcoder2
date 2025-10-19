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
    ll N,M;
    cin >> N >> M;
    priority_queue<ll> que;
    rep(i,N) {
        ll a; cin>>a;
        que.push(a);
    }
    rep(i,M) {
        auto q = que.top();
        que.pop();
        que.push(q/2);
    }
    ll ans = 0;
    while(!que.empty()) {
        auto q = que.top();
        que.pop();
        ans += q;
    }
    cout<< ans<<endl;
    return 0;
}