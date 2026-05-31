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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll H,W; cin>>H>>W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    int dy[] = {1, 0};
    int dx[] = {0, 1};
    queue<pair<ll,ll>> que;
    que.push({0,0});
    vector dist(H, vector<ll>(W));
    dist[0][0] = 1;
    while(!que.empty()) {
        auto [y,x] = que.front();
        que.pop();
        rep(k,2) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny >= H || nx >= W) continue;
            if(S[y][x] != '#') {
                if(dist[ny][nx] == 0) que.push({ny,nx});
                dist[ny][nx] += dist[y][x];
            }
        }
    }
    /*
    rep(i,H) {
        rep(j,W) cerr<<dist[i][j]<<" ";
        cerr<<endl;
    }
    */
    cout << dist[H-1][W-1] << endl;
    return 0;
}