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
    int H,W; cin>>H>>W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    queue<pii> que1, que2;
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};
    auto check = [&](int i, int j) -> bool {
        if(S[i][j] == '#') return false;        
        int cnt = 0;
        rep(k,4){
            int ny = dy[k] + i;
            int nx = dx[k] + j;
            if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if(S[ny][nx] == '#') cnt++;
        }
        if(cnt == 1) return true;
        else return false;
    
    };
    rep(i,H) rep(j,W) {
        if(check(i,j)) que1.push({i,j});
    }

    while(!que1.empty()){
        while(!que1.empty()) {
            auto [i,j] = que1.front();
            que1.pop();
            S[i][j] = '#';
            que2.push({i,j});
            rep(k,4){
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
                que2.push({ny, nx});
            }
        }
        while(!que2.empty()) {
            auto [i2,j2] = que2.front();
            que2.pop();
            if(check(i2,j2)) que1.push({i2,j2});
        }    
    }

    int ans = 0;
    rep(i,H) rep(j,W) {
        if(S[i][j] == '#') ans++;
    }
    cout << ans << endl;
    return 0;
} 