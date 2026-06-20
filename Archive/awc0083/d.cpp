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
    ll H,W,N;
    cin >> H >> W >> N;
    vector dist(H+2,vector<ll>(W+2,INF));
    for(int y=1;y<=H;y++) for(int x=1;x<=W;x++) dist[y][x]=INFi;
    dist[1][1]=0;
    while(N--) {
        int r,c; cin>>r>>c;
        dist[r][c] = INF;
    }
    queue<pair<int,int>> que;
    int dy[]={1,-1,0,0};
    int dx[]={0,0,1,-1};
    que.push({1,1});
    while(!que.empty()){
        auto [y,x] = que.front();
        que.pop();
        rep(k,4){
            ll ny=y, nx=x;
            while(dist[ny+dy[k]][nx+dx[k]]<INF){
                ny+=dy[k];
                nx+=dx[k];
            }
            if(chmin(dist[ny][nx], dist[y][x]+1)){
                que.push({ny,nx});
            }
        }
    }
    if(dist[H][W] == INFi) cout<<-1<<endl;
    else cout<<dist[H][W]<<endl;
    return 0;
}