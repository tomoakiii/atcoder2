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
typedef pair<ll,int> pli;
int main(){
    int N, M;
    cin >> N >> M;
    vector uv(N, vector<pli>{});
    rep(i,M) {
        int u,v; ll c;
        cin>>u>>v>>c;
        u--, v--;
        uv[u].push_back({v,c});
        uv[v].push_back({u,c});
    }
    vector dist(2, vector<ll>(N, INF));
    int st[] = {0, N-1};
    rep(kk, 2) {
        priority_queue<pli,vector<pli>,greater<pli>> que;
        que.push({0, st[kk]});
        dist[kk][st[kk]] = 0;
        while(!que.empty()) {
            auto [d, i] = que.top();
            que.pop();
            if(dist[kk][i] < d) continue;
            for(auto [nx,c]: uv[i]) {
                if(dist[kk][nx] <= dist[kk][i] + c) continue;
                dist[kk][nx] = dist[kk][i] + c;
                que.push({dist[kk][nx], nx});

            }
        }
    }
    ll ans = 2;
    for(int i=1; i<N-1; i++) {
        if(dist[0][i] + dist[1][i] == dist[0][N-1]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}