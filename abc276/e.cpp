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
    int H, W;
    cin >> H >> W;
    vector<string> G(H);
    rep(i,H) cin >> G[i];    
    vector visit(H, vector<int>(W, INFi));
    pair<int, int> start;
    rep(i,H) rep(j,W) {
        if (G[i][j] == 'S') {
            start = {i, j};
        }
    }
    
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    bool flg = false;
    auto f = [&](auto f, pair<int,int> cur, ll cnt){
        auto [i, j] = cur;
        visit[i][j] = cnt;        
        rep(k, 4) {
            int ni = i + dy[k];
            int nj = j + dx[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (G[ni][nj] == '#') continue;            
            if (G[ni][nj] == 'S' && cnt+1 >= 4) {
                flg = true;
                return;
            }
            if (visit[ni][nj] == INFi) {
                f(f, {ni, nj}, cnt+1);
            }
        }
    };
    f(f, start, 0);
    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}