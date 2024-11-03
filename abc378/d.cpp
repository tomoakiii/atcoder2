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
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> G(H);
    rep(i,H) cin >> G[i];    
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};



    auto func = [&](int y, int x)->ll {
        vector visit(H, vector<int>(W, INFi));
        bool flg = false;
        ll Kcnt = 0;        
        auto f = [&](auto f, pair<int,int> cur, ll cnt, set<pair<int, int>> hstr){
            auto [i, j] = cur;
            visit[i][j] = cnt;
            if (cnt == K) {
                Kcnt++;
                return;
            }
            hstr.insert({i, j});
            rep(k, 4) {
                int ni = i + dy[k];
                int nj = j + dx[k];
                if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                if (G[ni][nj] == '#') continue;                
                if (hstr.count({ni, nj}) == 0) {                    
                    f(f, {ni, nj}, cnt+1, hstr);
                }
            }
        };
        set<pair<int, int>> st;
        f(f, {y, x}, 0, st);
        return Kcnt;
    };
    

    ll ans = 0;
    rep(i,H) rep(j,W) {
        if(G[i][j] != '#') ans += func(i, j);
        // cout << endl;
    }
   
    cout << ans << endl;
    return 0;
}