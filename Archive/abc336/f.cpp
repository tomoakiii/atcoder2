#include <bits/stdc++.h>
using namespace std;

int main() {
    long long H, W;
    cin >> H >> W;
    vector<vector<int>> grid(H, vector<int>(W));
    auto goal = grid;
    int c = 0;
    for (int h=0; h<H; h++) for (int w=0; w<W; w++) {
        cin >> grid[h][w];
        goal[h][w]--;
        goal[h][w] = c++;        
    }
    
    vector<vector<long long>> list1(11), list2(11);
    int ind=1;
    list1[0].push_back(0);
    list2[0].push_back(0);
    for (int i=0; i<H; i++) for(int j=0; j<W; j++){
        list1[0][0] += ind * grid[i][j];
        list2[0][0] += ind * goal[i][j];
        ind *= 64;
    }

    for (int tr = 1; tr <= 10; tr++){
        long long p = 4;
        for (int i=2;i<=tr;i++) {
            p *= 3;
        }
        list1[tr].resize(p, 0ll);
        list2[tr].resize(p, 0ll);

        vector<int> rot(tr);
        for (int q=0; q<p; q++){
            long long pp = q;
            rot[0] = pp%4;
            pp /= 4;
            for (int t=1; t<tr; t++){
                pp /= 3;
                rot[t] = (rot[t-1] + pp%3 + 1) % 4;
            }

            int ct = 0;
            auto g1 = grid, g2 = goal;
            for (auto r: rot){
                ct++;
                int x, y, dH, dW;
                if (r==0) {x=0; y=0; dH=H-2; dW=W-2;}
                else if (r==1) {x=0; y=1; dH=H-1; dW=W-2;}
                else if (r==2) {x=1; y=0; dH=H-2; dW=W-1;}
                else if (r==3) {x=1; y=1;  dH=H-1; dW=W-1;}
                int cnt = 0, cmax = ((H-1) * (W-1) + 1)/2;
                for (int i=0; i<H-1; i++) for(int j=0; j<W-1; j++){
                    cnt++;
                    if (cnt > cmax){
                        break;
                    }
                    swap(g1[i+y][j+x], g1[dH-i][dW-j]);
                    swap(g2[i+y][j+x], g2[dH-i][dW-j]);
                }
                ind=1;
                for (int i=0; i<H; i++) for(int j=0; j<W; j++){
                    list1[tr][q] += ind * g1[i][j];
                    list2[tr][q] += ind * g2[i][j];
                    ind *= 64;
                }
            }
        }
        sort(list1[tr].begin(), list1[tr].end());
        sort(list2[tr].begin(), list2[tr].end());
    }
    int min1 = 100;
    for(int tr = 0; tr <= 10; tr){
        auto itr1 = list1[tr].begin();
        auto itr2 = list2[10].begin();        
        while (itr1 != list1[tr].end() && itr2 != list2[10].end()){
            if (*itr1 == list2[0][0]){
                cout << tr << endl;
                return 0;
            }
            if (*itr1 == *itr2){
                cout << tr + 10 << endl;
                return 0;
            }
            else if (*itr1 < *itr2){
                itr1++;
            } else {
                itr2++;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}