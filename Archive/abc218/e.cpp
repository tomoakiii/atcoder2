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
typedef pair<ll, pair<int,int>> pll;
int main(){
    ll N, M;
    cin >> N >> M;
    dsu UF(N);
    priority_queue<pll, vector<pll>, greater<pll>> que;
    ll sm = 0;
    rep(i,M) {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        u--, v--;
        que.push({c, {u,v}});
        sm += c;
    }
    while(!que.empty()) {
        auto [c, p] = que.top();
        que.pop();
        auto [u, v] = p;
        if(c<0) {
            UF.merge(u,v);
            sm -= c;
        } else {
            if(!UF.same(u,v)) {
                UF.merge(u,v);
                sm -= c;
            }
        }
    }
    cout << sm << endl;
    return 0;
}