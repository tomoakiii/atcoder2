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
    int H,W; cin>>H>>W;
    vector<string> S(H);
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    rep(i,H) cin>>S[i];
    ll mn = 0;
    rep(i1,H) rep(j1,W) {
        if(S[i1][j1] == '#') continue;
        ll ret = 0;
        vector dist(H, vector<ll>(W, INF));
        dist[i1][j1] = 0;
        queue<pair<pair<int,int>, ll>> que;
        que.push({{i1, j1}, 0});
        while(!que.empty()) {
            auto [yx, d] = que.front();
            auto [y,x] = yx;
            if(dist[y][x] < d) continue;
            que.pop();
            rep(k,4) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if(S[ny][nx] == '#') continue;
                if(dist[ny][nx] <= d + 1) continue;
                dist[ny][nx] = d + 1;
                que.push({{ny,nx}, dist[ny][nx]});
            }
        }
        rep(i2,H) rep(j2,W){
            if(dist[i2][j2] == INF) continue;
            chmax(mn, dist[i2][j2]);
        }        
    }
    cout << mn << endl;
    return 0;
}