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
        int ans = 0;            
        do {
            vector mm(H, vector<int>(W));
            int mx = 0;
            rep(y,H) rep(x,W) {
                if(x+1 < W && y+1 < H) {
                    int cnt = 0;
                    rep(i,2) rep(j,2) if(S[y+i][x+j] == '#') cnt++;
                    if(cnt==4){
                        rep(i,2) rep(j,2) {
                            mm[y+i][x+j]++;
                            chmax(mx, mm[y+i][x+j]);
                        }
                    }
                }
            }
            if(mx == 0) {
                break;
            }            
            rep(y,H) rep(x,W) {
                if(mm[y][x] == mx) {                    
                    S[y][x] = '.';
                    ans++;
                    for(int ny=y-1; ny<=y+1; ny++) for(int nx=x-1; nx<=x+1; nx++) {                        
                        if(ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                        if(mm[ny][nx] > 0) mm[ny][nx]--;
                    }
                }
            }
            rep(i,H) rep(j,W) chmax(mx, mm[i][j]);
        
        } while(true);
        cout << ans << endl;
    }
    return 0;
}