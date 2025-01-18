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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    vector visit(H, vector(W, vector<int>(2, INFi)));
    queue<pair<pair<int, int>, int>> que;
    rep(i, H) {
        cin >> S[i];
        rep(j, W) {
            if (S[i][j] == 'S') {
                que.push({{i, j}, 0});
                que.push({{i, j}, 1});
                visit[i][j][0] = 0;
                visit[i][j][1] = 0;
            }
        }
    }

    vector dy(2, vector<int>(2));
    vector dx(2, vector<int>(2));
    dy[0] = {1, -1};
    dx[0] = {0, 0};
    dy[1] = {0, 0};
    dx[1] = {1, -1};
    
    while(!que.empty()) {
        auto [p, d] = que.front();
        que.pop();
        auto [i, j] = p;
        rep(k, 2) {
            int ny = i + dy[d][k];
            int nx = j + dx[d][k];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if(S[ny][nx] == '#') continue;
            if(S[ny][nx] == 'G') {
                cout << visit[i][j][d] + 1 << endl;
                return 0;
            }
            int nd = (d==1)?0:1;
            if(visit[ny][nx][nd] <= visit[i][j][d] + 1 ){
                continue;
            }
            visit[ny][nx][nd] = visit[i][j][d] + 1;
            que.push({{ny, nx}, nd});
            
        }
    }
    cout << -1 << endl;    
    return 0;
}