#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W, K;
    cin >> H >> W >> K;
    char inp;
    vector<vector<char>> grid(H+1, vector<char>(W+1, 'x'));    
    
    for (int y=1; y<=H; y++){
        for (int x=1; x<=W; x++){
            cin >> inp;
            grid[y][x] = inp;
        }
    }

    int tc = max(W, H) + 1; // 最終出力
    int cx; // ここまでの連続非x出現数
    vector<int> cdv(W+1, 0); // その中にいくつdがあったか
    for (int y=1; y<=H; y++){        
        cx = 0;
        for (int x=1; x<=W; x++){
            if (grid[y][x] != 'x') {
                cx++;                
            } else {
                cx = 0;                
            }
            if (grid[y][x] == '.') {
                cdv[x] = cdv[x-1]+1;
            } else {
                cdv[x] = cdv[x-1];
            }

            if (cx >= K) {
                tc = min(tc, cdv[x]-cdv[x-K]);
            }
        }
    }
    vector<int> cdv2(H+1, 0); // その中にいくつdがあったか
    for (int x=1; x<=W; x++){
        cx = 0;
        for (int y=1; y<=H; y++){          
            if (grid[y][x] != 'x') {
                cx++;                
            } else {
                cx = 0;                
            }
            if (grid[y][x] == '.') {
                cdv2[y] = cdv2[y-1]+1;
            } else {
                cdv2[y] = cdv2[y-1];
            }          
            if (cx >= K) {
                tc = min(tc, cdv2[y]-cdv2[y-K]);
            }
        }
    }
    if (tc > max(W, H)){
        cout << -1 << endl;
    } else {
        cout << tc << endl;
    }    
    return 0;
}