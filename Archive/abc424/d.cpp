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
    int T; cin>>T;
    while(T--){
        ll H,W; cin>>H>>W;
        vector<string> S(H);
        rep(i,H) cin>>S[i];
        ll ans = INF;
        auto dfs = [&](auto dfs, int y, int x, ll nm) -> void{
            if(nm >= ans) return;
            int nx = x + 1;
            int ny = y;
            if(nx == W) {
                nx = 0; ny++;
            }            
            if(ny == H) {
                chmin(ans, nm);
            } else if(x+1 < W && y+1 < H) {
                int cnt = 0;
                rep(i,2) rep(j,2) if(S[y+i][x+j] == '#') cnt++;
                if(cnt==4){
                    for(int i=1; i>=0; i--) for(int j=1; j>=0; j--) {
                        S[y+i][x+j] = '.';
                        dfs(dfs, ny, nx, nm+1);
                        S[y+i][x+j] = '#';
                    }
                } else {
                    dfs(dfs, ny, nx, nm);
                }
            } else {
                dfs(dfs, ny, nx, nm);
            }
        };
        dfs(dfs, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}