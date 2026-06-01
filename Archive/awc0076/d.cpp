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
    int N,M,K;
    cin >> N >> M >> K;
    int sr,sc,gr,gc; cin>>sr>>sc>>gr>>gc;
    sr--,sc--,gr--,gc--;
    set<pair<int,int>> v;
    rep(i,K){
        int y,x; cin>>y>>x; y--,x--;
        v.insert({y,x});
    }
    vector<string> G(N);
    rep(i,N)cin>>G[i];
    set<pair< pair<int,int>, set<pair<int,int>> >> visit;
    visit.insert({{sr,sc}, v});
    int dy[]={-1,1,0,0,0};
    int dx[]={0,0,-1,1,0};
    int ans=INFi;
    priority_queue< tuple<int, pair<int,int>,set<pair<int,int>>> > que;
    que.push({0,{sr,sc},v});
    while(!que.empty()){
        auto [d, syx, rbt] = que.top();
        auto [sy,sx]=syx;
        d=-d;
        que.pop();
        rep(k,5){
            int ny=sy+dy[k];
            int nx=sx+dx[k];
            if(ny<0 || nx<0 || ny>=N || nx>=M){
                continue;
            }
            if(G[ny][nx]=='#')continue;
            if(rbt.contains({ny,nx}))continue;
            if(ny==gr && nx==gc){
                chmin(ans,d+1);
                break;
            }
            set<pair<int,int>> rbt2;
            bool flg=true;
            for(auto [ry,rx]:rbt){
                int nxy=ry, nxx=rx;
                int mn=INFi;
                rep(kk,5){
                    int nry=ry+dy[kk];
                    int nrx=rx+dx[kk];
                    if(nry<0 || nrx<0 || nry>=N || nrx>=M){
                        continue;
                    }
                    if(G[nry][nrx]=='#')continue;
                    if(chmin(mn, abs(nry-ny)+abs(nrx-nx))) {
                        nxy=nry, nxx=nrx;
                    }
                }
                if(mn==0) {
                    flg=false;
                    break;
                } else{
                    rbt2.insert({nxy,nxx});
                }
            }
            if(!flg) continue;
            if(visit.contains({{ny,nx}, rbt2}))continue;
            visit.insert({{ny,nx}, rbt2});
            que.push({-(d+1), {ny,nx}, rbt2});

        }
    };
    if(ans>=INFi) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}