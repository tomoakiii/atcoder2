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
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    vector dp(2*H+3, vector(2*W+3, vector<string>(H, string(W, '.'))));
    vector dist(2*H+3, vector<ll>(2*W+3, INF));
    vector score(2*H+3, vector<ll>(2*W+3, INF));
    int dy[] = {1, -1, 0, 0};
    int dx[] = {0, 0, 1, -1};
    queue<pair<pair<ll,ll>, pair<ll,ll>>> que;
    pair<int,int> TK;
    rep(i,H) {
        rep(j,W) {
            if(S[i][j] == 'T') TK = {i,j};
        }        
        dp[H+1][W+1][i] = S[i];
    }
    auto count = [&](int hind, int wind)->ll{
        int cnt = 0;
        rep(i,H) rep(j,W) if(dp[hind][wind][i][j] == '#') cnt++;
        return cnt;
    };
    dist[H+1][W+1] = 0;
    score[H+1][W+1] = count(H+1, W+1);
    que.push({{0,0}, {score[H+1][W+1],0}});
    ll ans = INF;
    while(!que.empty()) {
        auto [hw, sd] = que.front();
        auto [h,w] = hw;
        auto [sc,ds] = sd;
        que.pop();
        int hind = h+H+1, wind = w+W+1;
        if(score[hind][wind] < sc) continue;
        int cnt = count(hind, wind);
        if(cnt == 0) {
            chmin(ans, ds);
            continue;
        }
        rep(k,4) {
            int ny = dy[k] + h;
            int nx = dx[k] + w;
            int nyind = ny+H+1, nxind = nx+W+1;
            bool movable = false;
            int tky = TK.first + ny, tkx = TK.second + nx;
            if(tky >= H || tky < 0 || tkx >= W || tkx < 0) movable = true;
            else if(dp[hind][wind][tky][tkx] != '#') movable = true;
            if(!movable) continue;            
            int cnt2 = 0;
            vector<string> S2(H, string(W, '.'));
            for(int i=ny; i<ny+H; i++) for(int j=nx; j<nx+W; j++){
                if(i<0 || i>=H || j<0 || j>=W) continue;
                if(dp[hind][wind][i][j] == '#') {
                    S2[i][j] = '#';
                    cnt2++;
                }
            }
            if(score[nyind][nxind] <= cnt2) continue;
            rep(i,H) {
                dp[nyind][nxind][i] = S2[i];
            }
            score[nyind][nxind] = cnt2;
            dist[nyind][nxind] = ds+1;
            que.push({{ny,nx}, {cnt2,ds+1}});
        }
    }
    if(ans == INF) cout<<-1<<endl;
    else cout << ans << endl;
    return 0;
}