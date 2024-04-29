#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    vector grid(H, vector<int>(W, INFi));
    for(int i=0; i<H; i++){
        cin >> S[i];        
    }
    int lk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if (S[i][j] == '#') {
                grid[i][j] = -1;
                for (int k = 0; k < 4; k++){
                    int i2 = i+lk[k][0];
                    int j2 = j+lk[k][1];
                    if (i2 >= 0 && i2 < H && j2 >=0 && j2 < W) {
                        grid[i2][j2] = 0;
                    }
                }
            }
        }    
    }

    int mx = 1;
    int col = 0;  
    for(int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if (grid[i][j] == INFi){
                int cnt = 0;
                auto func = [&] (auto func, int x, int y, int col) -> void {
                    for (int k = 0; k < 4; k++){
                        int i2 = x+lk[k][0];
                        int j2 = y+lk[k][1];
                        if (i2 < 0 || i2 == H || j2 < 0 || j2 == W){
                            continue;
                        }
                         if (grid[i2][j2] == INFi) {
                            cnt++;
                            grid[i2][j2] = col;
                            func(func, i2, j2, col);
                        } else if (grid[i2][j2] <= 0 && grid[i2][j2] != -1*col){
                            cnt++;
                            grid[i2][j2] = -1*col;
                        } 
                    }
                };
                cnt++;
                grid[i][j] = ++col;
                func(func, i, j, col);
                mx = max(mx, cnt);
            }
        }
    }
    cout << mx << endl;
    return 0;
}