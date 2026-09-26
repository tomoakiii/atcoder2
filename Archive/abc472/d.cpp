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
    ll H,W,K;
    cin >> H >> W>> K;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    vector Gcn(H,vector<ll>(W));
    rep(i,H){
        ll cnt=0;
        rep(j,W) cnt+=(S[i][j]=='#');
        if(cnt==0) rep(j,W) Gcn[i][j]++;
    }
    rep(j,W){
        ll cnt=0;
        rep(i,H) cnt+=(S[i][j]=='#');
        if(cnt==0) rep(i,H) Gcn[i][j]++;
    }
    queue<pair<int,int>> que;
    vector dist(H, vector<ll>(W,INF));
    rep(i,H)rep(j,W)if(Gcn[i][j]==2){
        que.push({i,j});
        dist[i][j]=0;
    }
    int dy[]={-1,1,0,0};
    int dx[]={0,0,-1,1};
    while(!que.empty()){
        auto [i,j]=que.front();
        que.pop();
        rep(k,4){
            int ny=i+dy[k];
            int nx=j+dx[k];
            if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
            if(S[ny][nx] == '#') continue;
            if(chmin(dist[ny][nx], dist[i][j] + 1)) que.push({ny,nx});
        }
    }
    ll ans = 0;
    rep(i,H)rep(j,W)if(dist[i][j]<=K)ans++;
    cout<<ans<<endl;
    return 0;
}