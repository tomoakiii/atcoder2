#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
int main(){
    int N;
    cin >> N;
    int A, B, C, D;
    vector grid(100, vector<int>(100, false));
    int xmn = 100, xmx = 0, ymn = 100, ymx = 0;
    while(N--){
        cin >> A >> B >> C >> D;
        xmn = min(A, xmn);
        xmx = max(B, xmx);
        ymn = min(C, ymn);
        ymx = max(D, ymx);
        
        for (int x = A; x < B; x++){
            for (int y = C; y < D; y++){
                grid[y][x] = true;
            }
        }
    }
    int cnt = 0;
    for (int x = xmn; x < xmx; x++){
        for (int y = ymn; y < ymx; y++){
            if (grid[y][x]) cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}