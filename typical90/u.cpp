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
typedef pair<ll, int> pli;
int main(){
    int N, M;
    cin >> N >> M;
    vector<set<int>> uv(N);
    vector vu(N, vector<int>{});

    rep(i,M){
        int u, v;
        cin >> u >> v;
        u--, v--;
        uv[u].insert(v);
        vu[v].emplace_back(u);
    }

    vector<int> visit(N, -1);
    vector<bool> visit2(N, false);
    vector<int> dpt(N, 0);
    ll ans = 0;
    auto f = [&](auto f, int cur, int g, int d)->void{
        visit[cur] = g;
        visit2[cur] = true;
        dpt[cur] = d;
        for(auto nx: uv[cur]) {
            if (visit[nx] == g) {
                ll cnt = d - dpt[nx];
                if(cnt>1) ans += cnt * (cnt-1) / 2;
                else ans++;
                continue;
            }
            if(visit[nx] >= 0) continue;
            f(f, nx, g, d+1);
        }
    };
    int id = 0;
    rep(q, N) {
        visit.resize(N, 0);
        f(f, q, id++, 0);
    }
    cout << ans << endl;
    return 0;
}