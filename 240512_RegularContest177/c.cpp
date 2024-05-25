#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef pair<int, int> pii;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    rep(i, N) {
        cin >> S[i];
    }
    vector G(2, vector<vector<int>>(N, vector<int>(N, INFi)));
    G[0][0][0] = 0;
    G[1][0][N-1] = 0;
    queue<pii> que;    
    auto func = [&](int k, char col) -> void {
        while(!que.empty()){
            auto [y, x] = que.front();
            que.pop();
            auto dfs = [&](auto dfs, int ty, int tx) -> void{
                rep(j, 4){
                    int nx = tx+dx[j], ny=ty+dy[j];
                    if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
                    if(S[ny][nx] == col) {
                        if (G[k][ny][nx] > G[k][ty][tx]){
                            G[k][ny][nx] = G[k][ty][tx];
                            dfs(dfs, ny, nx);
                        }
                    } else {
                        if (G[k][ny][nx] > G[k][ty][tx]+1){
                            que.push({ny, nx});
                            G[k][ny][nx] = G[k][ty][tx]+1;
                        }                        
                    }
                }
            };
            dfs(dfs, y, x);
        }
    };
    que.push({0, 0});
    func(0, 'R');
    que.push({0, N-1});
    func(1, 'B');
    
    cout << G[0][N-1][N-1]+G[1][N-1][0] << endl;
    return 0;
}