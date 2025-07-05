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
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
int main(){
    int H,W; cin>>H>>W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    vector G(H, vector<int>(W, INFi));
    priority_queue<piii, vector<piii>, greater<piii>> que;
    que.push({0, {0,0}});
    int dy[] = {-1, 0, 0, 1};
    int dx[] = {0, 1, -1, 0};
    G[0][0] = 0;
    while(!que.empty()){
        auto [w, p] = que.top();
        auto [i, j] = p;
        que.pop();
        rep(k, 4){
            int ni = i + dy[k];
            int nj = j + dx[k];
            if(ni < 0 || nj < 0 || ni >= H || nj >= W) continue;
            if(S[ni][nj] != '.') continue;
            if(G[ni][nj] <= w) continue;
            G[ni][nj] = w;
            que.push({w, {ni, nj}});
        }
        for(int ky = -2; ky <= 2; ky++)for(int kx = -2; kx <= 2; kx++) {
            if(ky==-2 && kx==-2 || ky==-2 && kx==2 || ky==2 && kx==2 || ky==2 && kx==-2) continue; 
            int ni = i + ky;
            int nj = j + kx;
            if(ni < 0 || nj < 0 || ni >= H || nj >= W) continue;
            if(S[ni][nj] != '#') continue;
            if(G[ni][nj] <= w + 1) continue;
            G[ni][nj] = w + 1;
            que.push({w + 1, {ni, nj}});        
        }
    }
    cout<<G[H-1][W-1]<<endl;
    return 0;
}