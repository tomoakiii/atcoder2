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
typedef pair<ll,pair<int,int>> pli;

int main(){
    ll H,W; int sy, sx, gy, gx;
    cin >> H >> W >> sy >> sx >> gy >> gx;
    sx--, sy--, gx--, gy--;
    vector<string> S(H);
    rep(i,H){
        cin>>S[i];    
    }
    vector dist(H, vector<ll>(W, INF));
    dist[sy][sx] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> que;
    que.push({0,{sy,sx}});
    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    vector<int> wy, wx;
    for(int y = -2; y <= 2; y++) {
        for(int x = -2; x <= 2; x++) {
            if(abs(y) + abs(x) <= 1) continue;
            wy.push_back(y);
            wx.push_back(x);
        }
    }

    while(!que.empty()) {
        auto [d, p] = que.top();
        auto [y, x] = p;
        que.pop();
        if(d > dist[y][x]) continue;
        rep(i,4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if(dist[ny][nx] <= d) continue;
            if(S[ny][nx] == '#') continue;
            dist[ny][nx] = d;
            que.push({d, {ny,nx}});
        }
        rep(i, 20) {
            int ny = y + wy[i];
            int nx = x + wx[i];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if(dist[ny][nx] <= d+1) continue;
            if(S[ny][nx] == '#') continue;
            dist[ny][nx] = d+1;
            que.push({(d+1), {ny,nx}});
        }
    }
    if(dist[gy][gx] == INF) cout<<-1<<endl;
    else cout << dist[gy][gx] << endl;
    return 0;
}