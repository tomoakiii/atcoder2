#include <bits/stdc++.h>
using namespace std;


int main(){
    int W, B;
    cin >> W >> B;
    string S = "wbwbwwbwbwbw";
    
    for (int i=0; i<S.size(); i++){
        int cw = 0, cb = 0;
        for (int j=0; j<W+B; j++){
            if (S[(i + j)%S.size()] == 'w') cw++;
            else cb++;
            if (cw == W && cb == B) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "No" << endl;                
    return 0;
}