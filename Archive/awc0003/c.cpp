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
    ll N,K;
    cin >> N >> K;
    ll ans = 0;
    priority_queue<ll> que;
    rep(i,N) {
        ll a,b; cin>>a>>b;
        ans += a;
        que.push(a-b);
    }
    rep(i,K) {
        ans -= que.top();
        que.pop();
    }
    cout << ans << endl;
    return 0;
}