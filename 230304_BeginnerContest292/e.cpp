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
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<int>{});
    vector uvmat(N, vector<bool>(N));
    rep(i,M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uv[u].push_back(v);
        uvmat[u][v] = true;        
    }
    rep(i, N) uvmat[i][i] = true;
    ll cnt = 0;
    rep(i, N) {
        vector<bool> visit(N);
        auto f=[&](auto f, int cur)->void {
            visit[cur] = true;
            if (!uvmat[i][cur]) cnt++;
            for(auto nx : uv[cur]) {
                if (visit[nx]) continue;
                f(f, nx);
            }
        };
        f(f, i);
    }
    cout << cnt << endl;
    return 0;
}