#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<vector<vector<int>>>> dist;
vector<pair<int, int>> dir;
vector<string> g;

tuple<bool, int, int, int, int> ispath(int yy0, int xx0, int yy1, int xx1, int d){
    auto y0 = yy0 + dir[d].first;
    auto x0 = xx0 + dir[d].second;
    auto y1 = yy1 + dir[d].first;
    auto x1 = xx1 + dir[d].second;
    bool ismv0 = true;
    if (y0 >= N || y0 < 0 || x0 >= N || x0 < 0 || g[y0][x0] == '#') ismv0 = false;
    bool ismv1 = true;
    if (y1 >= N || y1 < 0 || x1 >= N || x1 < 0 || g[y1][x1] == '#') ismv1 = false;
    if (!ismv0 && !ismv1) return {false, 0, 0, 0, 0};
    if (!ismv0) return {true, yy0, xx0, y1, x1};
    if (!ismv1) return {true, y0, x0, yy1, xx1};
    else return {true, y0, x0, y1, x1};
}


int main(){
    cin >> N;
    dir.resize(4);
    dir[0] = {-1, 0}; dir[1] = {0, 1}; dir[2] = {1, 0}; dir[3] = {0, -1};
    const int INF = 0x0f0f0f0f;
    dist.resize(N);
    for(auto &d:dist){
        d.resize(N);
        for(auto &d2:d){
            d2.resize(N);
            for(auto &d3:d2){
                d3.resize(N, INF);
            }
        }
    }
    
    int y0, x0, y1, x1;
    bool b = false;
    string s;
    g.resize(N);
    for(int i=0; i<N; i++) {
        cin >> g[i];
        for(int j=0; j<N; j++) {
            if (g[i][j] == 'P'){
                if (!b) {
                    y0 = i; x0 = j;
                    b = true;
                } else {
                    y1 = i; x1 = j;
                }
                g[i][j] = '.';
            }
        }
    }
    dist[y0][x0][y1][x1] = 0;
    int di = 0;
    queue<tuple<int, int, int, int>> q;
    q.push({y0, x0, y1, x1});
    while (!q.empty()){
        auto [y0, x0, y1, x1] = q.front();
        q.pop();
        int c = dist[y0][x0][y1][x1];
        for(int i = 0 ; i < 4; i++){
            auto [b, yy0, xx0, yy1, xx1] = ispath(y0, x0, y1, x1, i);
            if (b) {
                if(yy0 == yy1 && xx0 == xx1){
                    cout << dist[y0][x0][y1][x1] + 1 << endl;
                    return 0;
                }
                if (dist[yy0][xx0][yy1][xx1] > INF/2){
                    dist[yy0][xx0][yy1][xx1] = dist[y0][x0][y1][x1] + 1;
                    q.push({yy0, xx0, yy1, xx1});
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}

