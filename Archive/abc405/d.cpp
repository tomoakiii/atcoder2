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
typedef pair<int,int> pii;

int main(){
    ll H, W;
    cin >> H >> W;    
    vector<string> S(H);
    queue<pii> que;
    vector Dist(H, vector<int>(W, INFi));
    vector Dir(H, vector<int>(W, 4));
    rep(i,H) {
        cin>>S[i];
        rep(j, W) {
            if(S[i][j] == 'E') {
                que.push({i,j});
                Dist[i][j] = 0;
            }
        }
    }
    int dy[] = {0,0,1,-1};
    int dx[] = {1,-1,0,0};

    while(!que.empty()) {
        auto [i,j] = que.front();
        que.pop();
        rep(k,4) {
            int ny = i + dy[k];
            int nx = j + dx[k];
            if(nx<0 || ny<0 || nx>=W || ny>=H) continue;
            if(S[ny][nx] == '#') continue;
            if(Dist[ny][nx] <= Dist[i][j] + 1) continue;
            Dist[ny][nx] = Dist[i][j] + 1;
            Dir[ny][nx] = k;
            que.push({ny,nx});
        }
    }
    char prt[] = {'<', '>', '^', 'v', 'x'};
    rep(i,H) {
        rep(j,W) {
            if(S[i][j] == '#' || S[i][j] == 'E') cout<< S[i][j];
            else cout << prt[Dir[i][j]];
        }
        printf("\n");
    }
    return 0;
}