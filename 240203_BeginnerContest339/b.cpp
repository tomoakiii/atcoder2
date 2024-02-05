#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<bool>> grid(H, vector<bool>(W, false));
    pair<int, int> pos = {0,0};
    vector<pair<int, int>> dir(4);
    dir[0] = {-1, 0}; dir[1] = {0, 1}; dir[2] = {1, 0}; dir[3] = {0, -1};
    int di = 0;
    while (N--){
        grid[pos.first][pos.second] = !grid[pos.first][pos.second];

        if (grid[pos.first][pos.second]) di++;
        else di--;
        if (di == 4) di = 0; else if (di < 0) di = 3;

        pos.first += dir[di].first;
        if (pos.first == H) pos.first = 0;
        else if (pos.first < 0) pos.first = H-1;

        pos.second += dir[di].second;
        if (pos.second == W) pos.second = 0;
        else if (pos.second < 0) pos.second = W-1;
    }

    for (const auto &h : grid) {
        for (const auto &w : h) {
            cout << (char)((w) ? '#':'.');
        }
        cout << '\n';
    } 
    return 0;
}

