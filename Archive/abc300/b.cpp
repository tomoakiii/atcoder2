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
    vector<string> A(H);
    vector<string> B(H);
    rep(i, H) cin>>A[i];
    rep(i, H) cin>>B[i];

    rep(p, H) rep(q, W) {
        bool flg = true;
        rep (i, H) rep(j, W) {
            if (A[(i+p)%H][(j+q)%W] != B[i][j]) {
                flg = false;
                break;
            }
            if (!flg) break;
        }
        if (flg) {
            cout << "Yes" << endl;
            return 0;
        }
    }    
    cout << "No" << endl;
    return 0;
}