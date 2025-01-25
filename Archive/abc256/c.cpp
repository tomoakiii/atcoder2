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

typedef struct{
    int grid[3][3];
}array_t;

int main(){
    vector<int> h(3), w(3);
    rep(i,3) cin>>h[i];
    rep(i,3) cin>>w[i];    
    auto judge = [&](const int g[2][2])->bool {
        int a[2];
        a[0] = h[0] - (g[0][0] + g[0][1]);
        a[1] = h[1] - (g[1][0] + g[1][1]);
        int b[2];
        b[0] = w[0] - (g[0][0] + g[1][0]);
        b[1] = w[1] - (g[0][1] + g[1][1]);
        rep(i, 2) if(a[i] <= 0 || b[i] <= 0) return false;
        int x = h[2] - (b[0] + b[1]);
        int y = w[2] - (a[0] + a[1]);
        if(x < 1 || y < 1) return false;
        if (x == y) {
            return true;
        }
        else return false;
    };
    
    ll cnt = 0;
    rep(i1, 30) rep(i2, 30) rep(i3, 30) rep(i4, 30) {
        int grid[2][2];
        grid[0][0] = i1+1;
        grid[0][1] = i2+1;
        grid[1][0] = i3+1;
        grid[1][1] = i4+1;
        if (judge(grid)) cnt++;
        
    }    
    cout << cnt << endl;
    return 0;
}