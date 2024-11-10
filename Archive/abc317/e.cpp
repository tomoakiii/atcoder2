#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
typedef pair<int, int> pii;
int main()
{    
    int H, W;
    cin >> H >> W;
    vector G(H, vector<int>(W, -1));
    string s;
    map<pii, int> mp;
    int lk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    pii st, gl;
    for(int i=0; i<H; i++){        
        cin >> s;        
        for (int j=0; j<W; j++){
            pii p = {i, j};
            if (s[j] == '.'){
                G[i][j] = 0;
            } else if (s[j] == 'S') {
                st = p;
                G[i][j] = 0;
            } else if (s[j] == 'G') {
                gl = p;
                G[i][j] = 0;
            } else if (s[j] == 'v') {
                mp[p] = 0;
            } else if (s[j] == '^') {
                mp[p] = 1;
            } else if (s[j] == '>') {
                mp[p] = 2;
            } else if (s[j] == '<') {
                mp[p] = 3;
            }
        }
    }

    
    for (auto m: mp){
        pii p = m.first;
        while (true){
            pii nx = {p.first + lk[m.second][0], p.second + lk[m.second][1]};
            if (nx.first < 0 || nx.first >= H || nx.second < 0 || nx.second >= W) break;
            if (G[nx.first][nx.second] == -1) break;
            G[nx.first][nx.second] = -2;
            p = nx;
        }
    }

    vector visit(H, vector<ll>(W, INF));
    visit[st.first][st.second] = 0;

    queue<pii> que;
    que.push(st);
    while (!que.empty()){
        pii q = que.front();
        que.pop();        
        for (int i=0; i<4; i++){
            pii nx = {q.first + lk[i][0], q.second + lk[i][1]};
            if (nx.first < 0 || nx.first >= H || nx.second < 0 || nx.second >= W) continue;
            if (G[nx.first][nx.second] < 0 ) continue;
            if (visit[nx.first][nx.second] <= visit[q.first][q.second] + 1) continue;
            visit[nx.first][nx.second] = visit[q.first][q.second] + 1;
            if (nx == gl){
                cout << visit[nx.first][nx.second] << endl;
                return 0;
            }
            que.push(nx);
        }
    }
    
    cout << -1 << endl;
    return 0;
}