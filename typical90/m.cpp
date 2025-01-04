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
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        uv[a].push_back({b, c});
        uv[b].push_back({a, c});
    }

    vector<ll> dist1(N, INF);
    dist1[0] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> que;
    que.push({0, 0});
    while( !que.empty() ) {
        auto [d, i] = que.top();
        que.pop();
        if(dist1[i] < d) continue;
        for(auto [nx, nd]: uv[i]) {
            nd += dist1[i];
            if(dist1[nx] <= nd) continue;
            que.push({nd, nx});
            dist1[nx] = nd;
        }
    }

    que.push({0, N-1});
    vector<ll> dist2(N, INF);
    dist2[N-1] = 0;
    while( !que.empty() ) {
        auto [d, i] = que.top();
        que.pop();
        if(dist2[i] < d) continue;
        for(auto [nx, nd]: uv[i]) {
            nd += dist2[i];
            if(dist2[nx] <= nd) continue;
            que.push({nd, nx});
            dist2[nx] = nd;
        }
    }
    rep(i, N) {
        printf("%lld\n", dist1[i] + dist2[i]);
    }

    return 0;
}