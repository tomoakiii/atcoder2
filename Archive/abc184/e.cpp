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
int main(){
    ll H,W; cin>>H>>W;
    vector<string> G(H);
    vector T(H, vector<ll>(W,-1));
    int M = 'Z'-'A'+1;
    vector alp(M, vector<pii>{});
    queue<pii> que;
    pii goal;
    vector<bool> visit(M,false);
    rep(i,H) {
        cin>>G[i];
        rep(j,W) {
            if(G[i][j] >= 'a' && G[i][j] <= 'z'){
                alp[G[i][j]-'a'].push_back({i,j});
            } else if (G[i][j] == 'S') {
                que.push({i,j});
                T[i][j] = 0;
            } else if (G[i][j] == 'G') {
                goal = {i,j};
            }
        }
    }
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    while(!que.empty()) {
        auto [i,j] = que.front();
        que.pop();
        if(G[i][j] >= 'a' && G[i][j] <= 'z') {
            if(!visit[G[i][j]-'a']){
                visit[G[i][j]-'a'] = true;
                for(auto [ny, nx]: alp[G[i][j]-'a']) {
                    if(T[ny][nx] == -1) {
                        T[ny][nx] = T[i][j] + 1;
                        que.push({ny,nx});
                    }
                }
            }
        }

        rep(k,4) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            if(ny >= H || ny < 0 || nx >= W || nx < 0) continue;
            if(G[ny][nx] == '#') continue;
            if(T[ny][nx] == -1) {
                T[ny][nx] = T[i][j] + 1;
                que.push({ny,nx});
            }
        }
    }
    cout << T[goal.first][goal.second] << endl;
            
    return 0;
}