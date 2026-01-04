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
int main(){
    ll H,W,T; cin>>H>>W>>T;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    pii st, ed;
    rep(i,H) rep(j,W) {
        if(S[i][j] == 'S') st = {i,j};
        if(S[i][j] == 'G') ed = {i,j};
    }
    ll l = 1, r = 1e10;
    int dy[] = {1,0,-1,0};
    int dx[] = {0,1,0,-1};
    while(r - l > 1) {
        ll c = (r+l)/2;
        queue<pii> que;
        que.push(st);
        vector dist(H, vector<ll>(W, INF));
        dist[st.first][st.second] = 0;
        while(!que.empty()) {
            auto [i,j] = que.front();
            que.pop();
            rep(k, 4) {
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                ll t = 1;
                if(S[ny][nx] == '#') t = c;
                if(dist[ny][nx] <= dist[i][j] + t) continue;
                dist[ny][nx] = dist[i][j] + t;
                que.push({ny,nx});
            }
        }
        if(dist[ed.first][ed.second] <= T) l = c;
        else r = c; 
    }
    cout << l << endl;
    return 0;
}