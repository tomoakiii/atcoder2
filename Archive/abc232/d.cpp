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
    vector<string> G(H);
    rep(i,H) cin>>G[i];
    int dy[] = {1, 0};
    int dx[] = {0, 1};
    queue<pair<int,int>> que;
    
    que.push({0,0});
    G[0][0] = '@';
    vector D(H, vector<int>(W, INFi));
    D[0][0] = 1;
    int mx = 0;
    while(!que.empty()) {
        auto [y,x] = que.front();
        que.pop();
        chmax(mx, D[y][x]);
        rep(k,2){
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if(G[ny][nx] == '#') continue;
            if(D[ny][nx] <= D[y][x] + 1) continue;
            D[ny][nx] = D[y][x] + 1;
            que.push({ny, nx});
        }
    }
    cout << mx << endl;
    return 0;
}