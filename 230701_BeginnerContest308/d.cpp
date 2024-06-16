#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);    
    string s;
    rep(i, H) {
        cin >> S[i];        
    }

    int lk[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    string T = "snuke";
    int TSIZE = T.size();
    bool flg = false;
    vector visit(H, vector<bool>(W, false));
    auto func = [&](auto func, int i, int j, int t)->void{        
        if (S[i][j] != T[t]){
            return;
        }
        visit[i][j] = true;
        // cout << i << " " << j << " " << S[i][j] << endl;
        if (i == H-1 && j == W-1){
            flg = true;
            return;
        }
        if(flg) return;
        rep (k, 4){
            int ni = i + lk[k][0];
            int nj = j + lk[k][1];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                continue;
            }
            if (visit[ni][nj] == true) continue;            
            func(func, ni, nj, (t+1)%TSIZE);
        }
    };
    func(func, 0, 0, 0);
    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}