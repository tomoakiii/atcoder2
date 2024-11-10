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
    ll N;
    cin >> N;
    map<ll, vector<ll>> AB;
    rep(i,N) {
        ll a, b;
        cin >> a >> b;
        AB[a].push_back(b);
        AB[b].push_back(a);
    }
    ll mx = 0;
    map<ll, bool> visit;
    auto f = [&](auto f, ll cur, ll pre)->void {
        chmax(mx, cur);
        visit[cur] = true;
        for(auto nx : AB[cur]) {
            if (nx == pre) continue;
            if (visit[nx]) continue;
            f(f, nx, cur);
        }
    };
    f(f, 1, 0);
    cout << mx << endl;
    return 0;
}