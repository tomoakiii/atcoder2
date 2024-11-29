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
    int H,W;
    cin>>H>>W;
    vector G(H, vector<char>(W));
    rep(y,H) rep(x,W) {
        cin>>G[y][x];
    }
    vector visit(H, vector<bool>(W));
    int y=0, x=0;
    while(true) {
        bool flg = true;
        if (G[y][x] == 'U') {
            if (y==0){
                flg = false;
            } else {
                y-=1;
            }
        } else if (G[y][x] == 'D') {
            if (y==H-1){
                flg = false;
            } else {
                y+=1;
            }
        } else if (G[y][x] == 'L') {
            if (x==0){
                flg = false;
            } else {
                x-=1;
            }
        } else if (G[y][x] == 'R') {
            if (x==W-1){
                flg = false;
            } else {
                x+=1;
            }
        }
        if(!flg) {
            cout << y+1 << " " << x+1 << endl;
            return 0;
        }
        if(visit[y][x]) {
            cout << -1 << endl;
            return 0;
        }
        visit[y][x] = true;
    }
    return 0;
}