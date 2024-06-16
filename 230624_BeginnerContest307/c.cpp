#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = ((n)-1); i >= 0; --i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int H, W;
    vector A(30, vector<bool>(30));
    auto B = A;
    auto X = A;
    string s;
    cin >> H >> W;
    
    int Ax=INFi, Ay=INFi, Ax2=0, Ay2=0;
    rep(i, H) {        
        cin >> s;
        rep(j, W) {
            A[i+9][j+9] = (s[j]=='#');
            if (A[i+9][j+9]){
                Ax = min(Ax, j+9);
                Ay = min(Ay, i+9);
                Ax2 = max(Ax2, j+9);
                Ay2 = max(Ay2, i+9);
            }
        }
    }
    
    int Bx=INFi, By=INFi, Bx2=0, By2=0;
    cin >> H >> W;
    rep(i, H) {
        cin >> s;
        rep(j, W) {
            B[i+9][j+9] = (s[j]=='#');
            if (B[i+9][j+9]){
                Bx = min(Bx, j+9);
                By = min(By, i+9);
                Bx2 = max(Bx2, j+9);
                By2 = max(By2, i+9);
            }            
        }
    }

    
    cin >> H >> W;
    rep(i, H) {
        cin >> s;
        rep(j, W) {
            X[i][j] = (s[j]=='#');
        }
    }
    rep(x, 19)rep(y, 19){ // Aループ 400回
        // x ~ [x + W], y ~ [y + H]
        if( Ax < x || Ay < y ) continue;
        if( Ax2 > x+W-1 || Ay2 > y+H-1 ) continue;
        rep(x2, 19)rep(y2, 19){ // Bループ 400回
            if( Bx < x2 || By < y2 ) continue;
            if( Bx2 > x2+W-1 || By2 > y2+H-1 ) continue;
            bool flg = true;
            rep(x3, W)rep(y3, H){ // Xループ 100回
                if (X[y3][x3] != (A[y+y3][x+x3] | B[y2+y3][x2+x3])) {
                    flg = false;
                    break;
                }
            }
            if (flg){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}