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
    ll H,W,D;
    cin >> H >> W >> D;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    vector visit(H, vector<ll>(W, -1));
    queue<pair<pair<int, int>, ll>> que;

    rep(i,H) rep(j,W) {
        if(S[i][j] == 'H') {
            visit[i][j] = D;
            if(D > 0) que.push({{i,j}, D});
        }
    }

    while(!que.empty()){
        auto [pii, rem] = que.front();
        auto [cury, curx] = pii;
        que.pop();
        rep(k, 4){
            int ny = cury + dy[k];
            int nx = curx + dx[k];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if(S[ny][nx] == '#') continue;
            if(visit[ny][nx] >= rem - 1) continue;
            visit[ny][nx] = rem-1;
            if(rem-1 == 0) continue;
            que.push({{ny, nx}, rem-1});
        }
    }


    ll ans = 0;
    rep(i, H) rep(j, W) {
        if(visit[i][j] >= 0) ans++;
    }

    cout << ans << endl;
    return 0;
}