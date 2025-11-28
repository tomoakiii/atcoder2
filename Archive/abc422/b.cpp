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
    int H,W;;
    cin >> H >> W;
    vector<string> G(H);
    rep(i,H) cin>>G[i];
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    rep(i,H) rep(j,W) {
        if(G[i][j] != '#') continue;
        int c = 0;
        rep(k,4) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            if(ny >= H || ny < 0 || nx >= W || nx < 0) continue;
            if(G[ny][nx] == '#') c++;
        }
        if(c != 2 && c != 4) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}