#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


void disp(vector<vector<bool>> G) {
    rep(i, G.size()) {
        rep(j, G[i].size()) {
            if (G[i][j]) cout << "#";
            else cout << " ";
        }
        cout << endl;
    }
}


int main(){
    vector G(15, vector<bool>(15));
    int len = 15;
    int r1 = 0, r2 = 14, c1 = 0, c2 = 14;
    for( ; r1 <= 7 ; r1+=2, c1+=2, r2-=2, c2-=2) {
        for(int i = r1; i <= r2; i++) { 
            G[i][c1] = true;
            G[i][c2] = true;
        }
        for(int j = c1; j <= c2; j++) { 
            G[r1][j] = true;
            G[r2][j] = true;
        }
    }
    int R, C;
    cin >> R >> C;
    R--, C--;
    // disp(G);
    if(G[R][C]) cout << "black" << endl;
    else cout << "white" << endl;
    
    return 0;
}