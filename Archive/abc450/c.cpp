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
    cin >> H>>W;
    vector<string> S(H);
    vector visit(H,vector<bool>(W));

    rep(i,H) cin>>S[i];
    int dy[]={1,-1,0,0};
    int dx[]={0,0,1,-1};

    bool flg;
    auto dfs = [&](auto dfs, int y, int x)->void{
        visit[y][x]=true;
        rep(k,4) {
            int ny=y+dy[k];
            int nx=x+dx[k];
            if(visit[ny][nx]) continue;
            if(S[ny][nx] == '#') continue;
            if(ny==0 || ny==H-1 || nx==0 || nx==W-1) {
                visit[ny][nx]=true;
                flg=false;
                continue;
            }
            dfs(dfs,ny,nx);
        }
    };
    ll ans=0;
    for(int i=1;i<H-1;i++)for(int j=1;j<W-1;j++) {
        if(visit[i][j] || S[i][j]=='#')continue;
        flg=true;
        dfs(dfs,i,j);
        if(flg)ans++;

    }
    cout<<ans<<endl;

    return 0;
}