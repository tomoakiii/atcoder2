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
    vector<ll> V(N);
    rep(i,N) cin>>V[i];
    ll ans = 0;
    rep(l, N+1) {
        rep(r, N+1) {
            ll sm = 0;
            if(l+r > K) break;
            if(l+r > N) break;
            ll rm = K - r - l;
            priority_queue<ll, vector<ll>, greater<ll>> que;
            rep(i,l) que.push(V[i]);
            rep(i,r) que.push(V[N-i-1]);
            rep(i,rm) {
                if(que.empty()) break;
                ll q = que.top();
                if(q < 0) que.pop();
                else break;
            }
            while(!que.empty()) {
                ll q = que.top();
                que.pop();
                sm += q;
            }
            chmax(ans, sm);
        }
    }
    cout << ans << endl;
    return 0;
}