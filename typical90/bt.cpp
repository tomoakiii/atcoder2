#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<unsigned int, unsigned int> pll;

int main(){
    unsigned int H, W;
    cin >> H >> W;
    vector<string> C(H);
    rep(i,H) cin>>C[i];
    
    auto hw = [&](uint y, uint x) -> ll {
        return y * W + x;
    };
    auto hwr = [&](uint x) -> pll {
        return make_pair(x/W, x%W);
    };

    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    ll ans = 0;    
    rep(i, H) rep(j, W) {
        if(C[i][j] == '#') continue;
        queue<pll> que;
        que.push({1<<hw(i,j), hw(i,j)});
        while(!que.empty()){
            auto [s, p] = que.front();
            que.pop();
            auto [y, x] = hwr(p); 
            rep(k, 4) {
                ll ny = y + dy[k];
                ll nx = x + dx[k];
                if(ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if(C[ny][nx] == '#') continue;
                if(ny == i && nx == j) {
                    chmax(ans, (ll)popcount(s));
                    continue;
                }
                if(((s>>hw(ny, nx)) & 1) > 0) continue;
                que.push({s|(1<<hw(ny, nx)), hw(ny, nx)});
            }   
        }
    }
    if(ans<3) ans = -1;
    cout << ans << endl;
    return 0;
}