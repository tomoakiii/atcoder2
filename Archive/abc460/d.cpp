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
    ll H,W; cin>>H>>W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];

    int dy[] = {-1,-1, -1, 0, 1, 1, 1,  0};
    int dx[] = {-1, 0, 1, 1,  1, 0, -1, -1};
    rep(kkk,2){
        vector<string> S2(H, string(W,'.'));
        rep(i,H)rep(j,W){
            if(S[i][j]=='.') {
                bool alw=true;
                rep(k,8){
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if(ny<0||ny>=H||nx<0||nx>=W)continue;
                    if(S[ny][nx]=='#') alw=false;
                }
                if(!alw)S2[i][j]='#';
            }
        }
        swap(S,S2);
    }

    vector dist(H,vector<ll>(W,INF));
    queue<pair<ll,ll>>que;
    rep(i,H)rep(j,W)if(S[i][j]=='#'){
        que.push({i,j});
        dist[i][j]=0;
    }
    while(!que.empty()){
        auto [i,j]=que.front();
        que.pop();
        rep(k,8){
            int ny=i+dy[k];
            int nx=j+dx[k];
            if(ny<0||ny>=H||nx<0||nx>=W)continue;
            if(chmin(dist[ny][nx], dist[i][j]+1)) que.push({ny,nx});
        }
    }
    vector<string> ans(H,string(W,'#'));
    rep(i,H)rep(j,W){
        if(dist[i][j]%2) ans[i][j]='.';
    }
    rep(i,H) cout<<ans[i]<<endl;
    return 0;
}