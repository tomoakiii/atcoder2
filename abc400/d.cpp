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
typedef pair<ll, ll> pll;
typedef pair<ll, pll> ppl;

int main(){
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin >> S[i];
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    priority_queue<ppl, vector<ppl>, greater<ppl>> que;
    que.push({0, {a, b}});
    vector cnt(H, vector<ll>(W, INF));
    cnt[a][b] = 0;
    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    while(!que.empty()) {
        auto [c, p] = que.top();
        que.pop();
        auto [a, b] = p;
        if(a==6 && b==2) {
            int xxxx=1;
        }
        rep(k, 4) {
            int ny = p.first + dy[k];
            int nx = p.second + dx[k];
            int nny = ny + dy[k];
            int nnx = nx + dx[k];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            int ad = 0;
            if(S[ny][nx] == '#') ad++;
            if(cnt[ny][nx] <= cnt[a][b] + ad) {
            } else {   
                cnt[ny][nx] = cnt[a][b] + ad;
                que.push({cnt[ny][nx], {ny, nx}});
            }
            if(ad == 0) continue;
            if(nny < 0 || nny >= H || nnx < 0 || nnx >= W) continue;            
            if(cnt[nny][nnx] <= cnt[a][b] + ad) continue;            
            cnt[nny][nnx] = cnt[a][b] + ad;
            que.push({cnt[nny][nnx], {nny, nnx}});
        }
    }

    cout << cnt[c][d] << endl;
    return 0;
}
