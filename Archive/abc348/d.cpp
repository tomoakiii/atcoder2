#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
int H, W;
struct xys{
        int x;
        int y;
    };
int main(){    
    cin >> H >> W;
    string s;
    vector<vector<int>> bg(H, vector<int>(W, 0));
    xys st, gl;    
    for(int i=0; i<H; i++)
    {
        cin >> s;
        for(int j=0; j<W; j++){
            if(s[j] == 'S') {
                st.x = j;
                st.y=i;
            }
            if(s[j] == 'T') {
                gl.x = j;
                gl.y=i;
            }
            if(s[j] == '#') bg[i][j] = -1;

        }
    }

    int N;
    cin >> N;
    int r, c, e;
    vector<int> dgv(N+1);
    for (int i=0; i<N; i++){
        cin >> r >> c >>e;
        bg[r-1][c-1] = e;
    }

    queue<xys> que;
    que.push(st);
    vector<vector<int>> visit(H, vector<int>(W, 0));
    int mv[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
    while (!que.empty()){
        auto q = que.front();
        que.pop();
        vector<vector<int>> mx(H, vector<int>(W, 0));
        if (bg[q.y][q.x] == 0) continue;
        mx[q.y][q.x] = bg[q.y][q.x];        
        queue<xys> ep;
        ep.push(q);
        while (!ep.empty()){
            auto e = ep.front();            
            ep.pop();            
            xys nx = e;            
            for (int i=0; i<4; i++){
                nx.y = e.y + mv[i][0];
                nx.x = e.x + mv[i][1];
                if (nx.y < 0 || nx.y >= H || nx.x < 0 || nx.x >= W || bg[nx.y][nx.x] == -1) {
                    continue;                    
                }
                if (nx.y == gl.y && nx.x == gl.x){
                    cout << "Yes" << endl;
                    return 0;
                }

                if (bg[nx.y][nx.x] > 0) {
                    if (visit[nx.y][nx.x] == 0){
                        visit[nx.y][nx.x] = 1;
                        que.push(nx);
                    }                    
                }
                if (mx[nx.y][nx.x] >= mx[e.y][e.x]-1) continue;
                mx[nx.y][nx.x] = mx[e.y][e.x] - 1;
                if (mx[nx.y][nx.x] > 0) {
                    ep.push(nx);
                }
            }
        }


    }

    cout << "No" << endl;
    return 0;
}