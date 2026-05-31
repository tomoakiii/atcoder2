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
    int H,W; cin>>H>>W;
    if(H==1 && W==1) {
        cout<<"Draw"<<endl;
        return 0;
    }
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    vector A(H, vector<ll>(W));    
    rep(i,H) rep(j,W) A[i][j] = (S[i][j]=='+')?1:-1;
    vector exp(H, vector<ll>(W, 0));
    vector visit(H, vector<bool>(W));
    queue<pair<int,int>> que;    
    visit[H-1][W-1] = true;
    if(H>1) {
        visit[H-2][W-1] = true;        
        que.push({H-2,W-1});
    }
    if(W>1) {
        visit[H-1][W-2] = true;
        que.push({H-1,W-2});
    }
    while(!que.empty()) {
        auto [y,x] = que.front();        
        que.pop();

        if((y+x)%2 == 0) {
            exp[y][x] = -INF;
            // Takahashi
            if(y<H-1) chmax(exp[y][x], exp[y+1][x] + A[y+1][x]);
            if(x<W-1) chmax(exp[y][x], exp[y][x+1] + A[y][x+1]);
        } else {
            // Aoki
            exp[y][x] = INF;
            if(y<H-1) chmin(exp[y][x], exp[y+1][x] - A[y+1][x]);
            if(x<W-1) chmin(exp[y][x], exp[y][x+1] - A[y][x+1]);
        }

        if(y>0 && !visit[y-1][x]) {
            visit[y-1][x] = true;
            que.push({y-1,x});
        }
        if(x>0 && !visit[y][x-1]) {
            visit[y][x-1] = true;
            que.push({y,x-1});
        }
    }

    if(exp[0][0] > 0) cout<<"Takahashi"<<endl;
    else if(exp[0][0] == 0) cout<<"Draw"<<endl;
    else cout<<"Aoki"<<endl;

    return 0;
}