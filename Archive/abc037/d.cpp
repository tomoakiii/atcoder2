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
typedef modint1000000007 mint;
typedef pair<ll, pair<int,int>> pli;
int main(){
    ll H,W;
    cin >> H >> W;
    vector A(H, vector<ll>(W));
    int dy[] = {1,-1,0,0};
    int dx[] = {0,0,1,-1};
    priority_queue<pli> que;
    rep(i,H) rep(j,W) {
        cin>>A[i][j];
        que.push({A[i][j], {i,j}});
    }
    vector dp(H, vector<mint>(W,1));
    while(!que.empty()) {
        auto [v, ij] = que.top();
        que.pop();
        auto [i, j] = ij;
        rep(k,4) {
            int ny = dy[k] + i;
            int nx = dx[k] + j;
            if(ny >= H || ny < 0 || nx >= W || nx < 0) continue;
            if(A[ny][nx] < A[i][j]) {
                dp[ny][nx] += dp[i][j];
            }
        }
    }
    mint ans = 0;
    rep(i,H)rep(j,W) ans+=dp[i][j];
    cout<<ans.val()<<endl;
    return 0;
}