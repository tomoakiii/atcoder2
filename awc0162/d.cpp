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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll H,W,R,C;
    cin >> H >> W >> R >> C;
    R--,C--;
    vector<string> G(H);
    rep(i,H)cin>>G[i];

    vector dp(H, vector<ll>(W,INF));
    dp[R][C]=0;
    ll M='z'-'a'+1;
    ll N; string S;
    cin>>N>>S;
    int dy[]={-1,0,1,0};
    int dx[]={0,-1,0,1};

    rep(n,N){
        typedef pair<ll, pair<int,int>> pp;
        priority_queue<pp,vector<pp>,greater<pp>> que;
        vector dp2(H, vector<ll>(W,INF));
        rep(i,H)rep(j,W)if(dp[i][j]<INF){
            dp2[i][j]=dp[i][j];
            que.push({dp2[i][j],{i,j}});
        }

        while(!que.empty()){
            auto [d, yx] = que.top();
            que.pop();
            auto [y,x] = yx;
            if(dp2[y][x] < d)continue;
            rep(k,4){
                int ny=dy[k]+y;
                int nx=dx[k]+x;
                if(nx<0||ny<0||ny>=H||nx>=W)continue;
                if(chmin(dp2[ny][nx], d+1)) que.push({dp2[ny][nx], {ny,nx}});
            }
        }
        rep(i,H)rep(j,W)if(G[i][j]!=S[n])dp2[i][j]=INF;
        swap(dp,dp2);
    }
    ll ans = INF;
    rep(i,H)rep(j,W)chmin(ans, dp[i][j]);
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans+S.size()<<endl;
    return 0;
}