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
typedef pair<ll, pii> pll;
int main(){
    ll N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    priority_queue<pll,vector<pll>, greater<pll>> que;
    que.push({0, {0,0}});
    int dy[]={0,0,1,-1};
    int dx[]={1,-1,0,0};
    vector dp(N,vector<ll>(M,INF));
    dp[0][0] = 0;
    while(!que.empty()) {
        auto [v,yx] = que.top();
        que.pop();
        auto [y,x] = yx;
        if(dp[y][x] < v) continue;
        rep(k,4) {
            int ny=y+dy[k];
            int nx=x+dx[k];
            if(ny<0||ny>=N||nx<0||nx>=M) continue;
            int ad = (S[ny][nx]=='#')?1:0;
            if(chmin(dp[ny][nx], dp[y][x] + ad)) que.push({dp[ny][nx], {ny,nx}});
        }
    }
    cout << dp[N-1][M-1] << endl;
    return 0;
}