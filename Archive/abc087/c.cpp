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
    ll N;
    cin >> N;
    int H = 2, W = N;
    vector A(2, vector<ll>(N));
    rep(i,2)rep(j,N) cin>>A[i][j];
    int dy[] = {0,1};
    int dx[] = {1,0};
    queue<pair<int,int>> que;
    que.push({0,0});
    vector V(2, vector<ll>(N));
    V[0][0] = A[0][0];
    while(!que.empty()) {
        auto [y,x] = que.front();
        que.pop();
        rep(k,2) {
            int ny = dy[k] + y;
            int nx = dx[k] + x;
            if(ny >= H || nx >= W) continue;
            if(chmax(V[ny][nx], V[y][x] + A[ny][nx])) que.push({ny,nx});
        }
    }
    cout<<V[H-1][W-1]<<endl;
    return 0;
}