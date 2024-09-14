#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll H,W;
    cin >> H >> W;
    vector<string> G(H);
    ll si, sj;
    cin >> si >> sj;
    si--; sj--;
    rep(i,H) {
        cin >> G[i];
    }
    string X;
    cin >> X;
    for(char c:X) {
        ll dy=si, dx=sj;
        if(c == 'L') {
            dx-=1;
        } else if (c == 'R') {
            dx+=1;
        } else if (c == 'U') {
            dy-=1;
        } else if (c == 'D') {
            dy+=1;
        }

        if (dx >= W || dx < 0 || dy >= H || dy < 0) {
            continue;
        }
        if (G[dy][dx] == '#'){
            continue;
        }
        si = dy;
        sj = dx;
    }
    si++; sj++;
    cout << si << " " << sj << endl;
    return 0;
}