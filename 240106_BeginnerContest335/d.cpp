#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<string>> grid(N, vector<string>(N, "0"));
    grid[N/2][N/2]= "T";
    char dir = 'R'; // 0:R, 1:D, 2:L, 3:U
    char tar = 0;
    int y=0, x=0, num = 1;
    while (grid[y][x][0] != 'T'){
        grid[y][x] = to_string(num++);
        switch (dir) {
            case 'R':
                if (x == N-1 || grid[y][x+1][0] != '0') dir = 'D';
                break;
            case 'D':
                if (y == N-1 || grid[y+1][x][0] != '0') dir = 'L';
                break;
            case 'L':
                if (x == 0 || grid[y][x-1][0] != '0') dir = 'U';
                break;
            case 'U':
                if (y == 0 || grid[y-1][x][0] != '0') dir = 'R';
                break;
        }
        switch (dir) {
            case 'R': x++; break;
            case 'D': y++; break;
            case 'L': x--; break;
            case 'U': y--; break;
        }
    }

    for(auto a:grid) {
        for (auto b:a) cout<<b<<" ";
        cout << endl;
    }

    return 0;
}

