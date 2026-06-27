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
    ll N;
    cin >> N;
    vector<string> S(N);
    vector dist(N, vector<ll>(N, INF));
    queue<pair<ll,ll>> que;
    pair<ll,ll> goal;
    rep(i,N) {
        cin>>S[i];
        rep(j,N) {
            if(S[i][j]=='S') {
                dist[i][j]=1;
                que.push({i,j});
            }
            if(S[i][j]=='G') {
                goal = {i,j};
            }
        }
    }
    vector<ll> dx={1,0,-1,0};
    vector<ll> dy={0,1,0,-1};
    while(!que.empty()) {
        auto [x,y] = que.front();
        que.pop();
        rep(i,4) {
            ll nx = x+dx[i];
            ll ny = y+dy[i];
            if(nx<0||nx>=N||ny<0||ny>=N) continue;
            if(S[nx][ny]=='#') continue;
            if(chmin(dist[nx][ny], dist[x][y]+1)) {
                que.push({nx,ny});
            }
        }
    }
    if(dist[goal.first][goal.second]==INF) {
        cout << -1 << endl;
    } else {
        cout << dist[goal.first][goal.second] << endl;
    }
    return 0;
}