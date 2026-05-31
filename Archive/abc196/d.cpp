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

int main(){
    ll H,W,A,B; cin>>H>>W>>A>>B;
    vector Grid(H, vector<int>(W));
    ll cnt = 0;
    auto f = [&](auto f, vector<vector<int>> G, int y, int x, int rA)->void{        
        int nx, ny;
        if(rA==0) {            
            cnt++;
            return;            
        }
        if(y >= H) return;
        if(x+1 >= W) f(f, G, y+1, 0, rA); // No place
        else f(f, G, y, x+1, rA); // No place
        if(G[y][x] == 1) return;
        G[y][x] = 1;
        if(x < W-1 && G[y][x+1] == 0) {
            G[y][x+1] = 1;
            if(x+2>=W) f(f, G, y+1, 0, rA-1);
            else f(f, G, y, x+2, rA-1);
            G[y][x+1] = 0;
        }
        if(y < H-1 && G[y+1][x] == 0) {
            G[y+1][x] = 1;
            if(x+1>=W) f(f, G, y+1, 0, rA-1);
            else f(f, G, y, x+1, rA-1);
            G[y+1][x] = 0;
        }
    };
    f(f, Grid, 0, 0, A);
    cout<<cnt<<endl;
    return 0;
}