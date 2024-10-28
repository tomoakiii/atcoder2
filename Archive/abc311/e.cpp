#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll H, W, N;
    cin >> H >> W >> N;
    vector G(H, vector<ll>(W, INF));
    for (int y=0; y<H; y++) G[y][0] = 1;
    for (int x=0; x<W; x++) G[0][x] = 1;
    for(int i=0; i<N;i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a][b] = 0;
    }
    for (int y=1; y<H; y++)for (int x=1; x<W; x++){
        if (G[y][x] == 0) continue;
        G[y][x] = min(min(G[y-1][x], G[y][x-1]), G[y-1][x-1])+1;
    }
    ll sm = 0;
    for (int y=0; y<H; y++)for (int x=0; x<W; x++){
        sm += G[y][x];
    }
    cout << sm << endl;
    return 0;
}