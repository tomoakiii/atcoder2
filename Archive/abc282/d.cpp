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
    vector uv(N, vector<int>{});
    vector<ll> tM(N);
    dsu ds(N);
    rep(i,M) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
        ds.merge(u,v);
    }

    rep(i, N) {
        tM[ds.leader(i)] += uv[i].size();
    }
    rep(i, N) {
        tM[i] /= 2;
    }

    vector<int> visit(N, -1);
    ll ans = 0, ps = 0;
    for(auto v: ds.groups()) {
        int pl = ds.leader(v[0]);
        ll a = v.size();
        ans += a * ps;
        queue<int> que;
        que.push(pl);
        visit[pl] = 0;
        ll b=0,w=0;
        while(!que.empty()) {
            auto q = que.front();
            if(visit[q] == 0) {
                w++;
            }
            else {
                b++;
            }
            que.pop();
            for(auto p: uv[q]) {
                if (visit[p] == visit[q]) {
                    cout << 0 << endl;
                    return 0;
                }
                if (visit[p] == -1) {
                    visit[p] = (visit[q]==0)?1:0;
                    que.push(p);
                }
            }
        }
        ans += (b*w) - tM[pl];
        ps += a;
    }
    cout << ans << endl;
    return 0;
}