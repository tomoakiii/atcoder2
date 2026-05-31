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
typedef pair<ll,ll> pll;
vector wp('z'-'a' + 1, vector<pll>{});
int main(){
    ll H,W; cin>>H>>W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    rep(i,H) rep(j, W) {
        if('a' <= S[i][j] && S[i][j] <= 'z') {
            wp[S[i][j]-'a'].push_back({i,j});
        }
    }
    vector<bool> visit('z'-'a'+1);
    rep(i, wp.size()){
        if(wp[i].size() < 2) visit[i] = true;
    }
    vector dist(H, vector<ll>(W,INF));
    dist[0][0] = 0;
    queue<pair<pll, ll>> que;
    que.push({{0,0},0});
    int dy[] = {0,0,1,-1};
    int dx[] = {1,-1,0,0};
    while(!que.empty()) {
        auto [ij, d] = que.front();
        auto [i,j] = ij;
        que.pop();
        if(dist[i][j] < d) continue;
        rep(k,4) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if(S[ny][nx] == '#') continue;
            if(dist[ny][nx] <= dist[i][j] + 1) continue;
            dist[ny][nx] = dist[i][j] + 1;
            que.push({{ny,nx}, dist[ny][nx]});
        }
        if('a' <= S[i][j] && S[i][j] <= 'z') {
            int id = S[i][j] - 'a';
            if(visit[id]) continue;
            visit[id] = true;
            for(auto [ny, nx]: wp[id]) {
                if(ny == i && nx == j) continue;
                if(dist[ny][nx] <= dist[i][j] + 1) continue;
                dist[ny][nx] = dist[i][j] + 1;
                que.push({{ny,nx}, dist[ny][nx]});
            }
        }
    }
    if(dist[H-1][W-1] < INF) cout << dist[H-1][W-1] << endl;
    else cout<<-1<<endl;
    return 0;
}