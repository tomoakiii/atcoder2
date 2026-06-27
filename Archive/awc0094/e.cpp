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
    typedef pair<int,int> pii;
    typedef pair<ll,pii> pli;
    priority_queue<pli,vector<pli>,greater<pli>>que;
    vector<string> S(H);
    vector dist(H,vector<ll>(W,INF));
    int gy,gx;
    rep(i,H) {
        cin>>S[i];
        rep(j,W) {
            if(S[i][j]=='S'){
                dist[i][j] = 0;
                que.push({dist[i][j],{i,j}});
            } else if(S[i][j] == 'G'){
                gy=i, gx=j;
            }
        }
    }
    int dy[]={1,-1,0,0};
    int dx[]={0,0,1,-1};
    while(!que.empty()){
        auto [d,ij]=que.top();
        auto [i,j] = ij;
        que.pop();
        if(dist[i][j] < d)continue;
        rep(k,4){
            int ny=i+dy[k];
            int nx=j+dx[k];
            if(ny<0||nx<0||ny>=H||nx>=W)continue;
            ll v;
            if(S[ny][nx]=='X')continue;
            if(S[i][j]=='V' && S[ny][nx]=='V') v=0;
            else if(S[ny][nx]=='V') v=2;
            else v=1;
            if(chmin(dist[ny][nx], dist[i][j] + v)){
                que.push({dist[ny][nx], {ny,nx}});
            }
        }
    }
    ll ans=dist[gy][gx];
    if(ans<INF)cout<<ans<<endl;
    else cout<<"NO"<<endl;
    return 0;
}