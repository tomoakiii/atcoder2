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
    ll H,W;
    cin >> H>>W;
    int sy, sx, gy, gx;
    cin>>sy>>sx>>gy>>gx;
    sy--, sx--, gy--,gx--;
    vector<string> G(H);
    rep(i,H) cin>>G[i];
    int dy[] = {1,-1,0,0};
    int dx[] = {0,0,1,-1};
    queue<pair<int,int>> que;
    que.push({sy,sx});
    vector dist(H, vector<int>(W,INFi));
    dist[sy][sx] = 0;
    while(!que.empty()){
        auto [y,x] = que.front();
        que.pop();
        rep(k,4) {
            int ny = dy[k]+y;
            int nx = dx[k]+x;
            if(ny<0||ny>=H||nx<0||nx>=W) continue;
            if(dist[ny][nx] <= dist[y][x] + 1) continue;
            if(G[ny][nx] == '#') continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.push({ny,nx});
        }
    }
    cout << dist[gy][gx] << endl;
    return 0;
}