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
    ll H,W; cin>>H>>W;
    vector A(H, vector<ll>(W));    
    rep(i,H) {
        rep(j,W) cin>>A[i][j];
    }
    vector<ll> P(H+W-1);
    rep(i, H+W-1) cin>>P[i];
    
    int dy[] = {1,0};
    int dx[] = {0,1};
    auto chk = [&](ll c)->bool{
        queue<pair<int,int>> que;               
        vector dp(H, vector<ll>(W, -INF));
        dp[0][0] = c + A[0][0] - P[0];
        if(dp[0][0] < 0) return false;
        que.push({0, 0});
        vector visit(H, vector<bool>(W));
        while(!que.empty()) {
            auto [q,d] = que.front();
            int y = q/W;
            int x = q%W;
            que.pop();            
            rep(k,2) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                int nd = d+1;
                if(ny >= H || nx >= W) continue;
                ll cur = dp[y][x] + A[ny][nx] - P[nd];
                if(cur < 0) continue;
                chmax(dp[ny][nx], cur);
                if(!visit[ny][nx]) que.push({ny*W+nx, nd});
                visit[ny][nx] = true;
            }
        }
        return (dp[H-1][W-1] >= 0);
    };
    
    if(chk(0)) {
        cout<<0<<endl;
        return 0;
    }
    ll l = 0, r = 1E15;
    while(r-l > 1) {
        ll c = (r+l)/2;
        if(chk(c)) r = c;
        else l = c;
    }
    cout<<r<<endl;
    return 0;
}