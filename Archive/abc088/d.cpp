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
    ll wc = 0;
    rep(i,H) {
        cin>>S[i];
        rep(j,W) {
            if(S[i][j] == '.') wc++;
        }
    }
    queue<pair<int,int>> que;
    que.push({0,0});
    vector dist(H, vector<ll>(W, INF));
    dist[0][0] = 1;
    int dy[] = {0,0,1,-1};
    int dx[] = {1,-1,0,0};
    while(!que.empty()) {
        auto [i,j] = que.front();
        que.pop();
        rep(k,4) {
            int ny = dy[k] + i;
            int nx = dx[k] + j;
            if(ny<0||ny>=H||nx<0||nx>=W) continue;
            if(S[ny][nx] == '#') continue;
            if(dist[ny][nx] <= dist[i][j] + 1) continue;
            dist[ny][nx] = dist[i][j] + 1;
            que.push({ny,nx});
        }
    }
    if(dist[H-1][W-1] == INF) cout<<-1<<endl;
    else cout<<wc - dist[H-1][W-1]<<endl;
    return 0;
}