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
typedef modint1000000007 mint;
typedef pair<int, int> pii;
typedef tuple<int, int, int, int> tiii;

int main(){
    int H, W;
    cin >> H >> W;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--, cs--, rt--, ct--;
    vector<string> S(H);
    rep(i,H) {
        cin>>S[i];
    }
    vector num(H, vector(W, vector<int>(4, INFi)));
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    rep(i,4) {
        pq.push({0, i, rs, cs});
        num[rs][cs][i] = 0;
    }
    int dy[] = {1, -1, 0, 0};
    int dx[] = {0, 0, 1, -1};
    int ans = INFi;
    while(!pq.empty()) {
        auto [c, d, y, x] = pq.top();
        pq.pop();
        rep(i, 4) {
            int nc= c;
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;            
            if(S[ny][nx] == '#') continue;
            if(i != d) nc++;
            if(num[ny][nx][i] <= nc) continue;
            num[ny][nx][i] = nc;
            if(ny == rt && nx == ct) {
                chmin(ans, nc);
                continue;   
            }
            pq.push({nc, i, ny, nx});
        }
    }
    cout << ans << endl;
    return 0;
}