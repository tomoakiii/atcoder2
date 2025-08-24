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
typedef pair<int,int> pii;
typedef pair<pii,pii> ppii;
int main(){
    ll H,W;
    cin >> H >> W;
    vector<string> G(H);
    queue<ppii> que;
    pii goal;
    vector dist(H, vector(W, vector<ll>(2, INF)));
    rep(i,H) {
        cin>>G[i];
        rep(j,W) {
            if(G[i][j] == 'S') {
                que.push({{i,j}, {0,0}}); // (i,j), (switch, dist)
                dist[i][j][0] = 0;
            } else if(G[i][j] == 'G') goal = {i,j};
        }
    }
    
    int dy[4] = {0,0,1,-1};
    int dx[4] = {1,-1,0,0};
    while(!que.empty()) {
        auto [q1, q2] = que.front();
        auto [i, j] = q1;
        auto [sw, d] = q2;
        que.pop();
        if(dist[i][j][sw] < d) continue;
        rep(k,4) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            if(ny >= H || ny < 0 || nx >= W || nx < 0) continue;
            if(G[ny][nx] == '#') continue;
            if(sw == 0 && G[ny][nx] == 'x') continue;
            if(sw == 1 && G[ny][nx] == 'o') continue;
            int nsw = sw;
            if(G[ny][nx] == '?') nsw = (sw + 1)%2;
            if(dist[ny][nx][nsw] <= d + 1) continue;
            dist[ny][nx][nsw] = d + 1;
            que.push({{ny,nx}, {nsw, d+1}});
        }
    }
    ll ans = min(dist[goal.first][goal.second][0], dist[goal.first][goal.second][1]);
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}