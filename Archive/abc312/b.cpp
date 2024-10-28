#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
int main(){
    int N, M;
    cin >> N >> M;
    vector<string> tak(9);
    tak[0] = "###.?????";
    tak[1] = "###.?????";
    tak[2] = "###.?????";
    tak[3] = "....?????";
    tak[4] = "?????????";
    tak[5] = "?????....";
    tak[6] = "?????.###";
    tak[7] = "?????.###";
    tak[8] = "?????.###";

    vector<string> grid(N);
    for (int i=0; i<N; i++) cin>>grid[i];

    for (int i=0; i<N-8; i++) for (int j=0; j<M-8; j++)
    {
        bool flag=true;
        for (int x=0; x<4; x++) for (int y=0; y<4; y++)
        {
            if (tak[x][y] != grid[i+x][j+y] || tak[8-x][8-y] != grid[i+8-x][j+8-y]) {
                flag = false;
            }
        }
        if (flag) {
            cout << (i+1) << " " << (j+1) << endl;
        }
    }
    
    return 0;
}

