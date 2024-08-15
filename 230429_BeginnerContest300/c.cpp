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
    vector<string> C(H);
    rep(i, H) cin>>C[i];

    int dx[] = {-1, -1, 1, 1};
    int dy[] = {1, -1, -1, 1};
    vector<int> ans(min(H,W));
    for (int i=1; i<H-1; i++) for (int j=1; j<W-1; j++) {
        if (C[i][j] != '#') continue;
        bool flg = true;
        for (int n=1; n<min(H,W); n++) {
            rep(k, 4) {
                int ni = i + n*dy[k], nj = j + n*dx[k];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                    flg = false;
                    break;
                }
                if (C[ni][nj] != '#') {
                    flg = false;
                    break;
                }
            }
            if (!flg) {
                if (n > 1) {
                    ans[n-2]++;
                }
                break;
            }
        }
    }
    for(auto v: ans) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}