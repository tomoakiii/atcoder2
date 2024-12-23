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
    ll H, W, X, Y;
    cin >> H >> W >> X >> Y;
    X--, Y--;
    vector<string> S(H);
    rep(i,H) cin>>S[i];

    string T;
    cin >> T;
    ll ans = 0;
    vector visit(H, vector<bool>(W, false));
    visit[X][Y] == true;
    if(S[X][Y] == '@') ans++;
    for(auto t:T) {
        int nx = X;
        int ny = Y;
        if(t == 'U') {
            nx--;
        } else if(t == 'D') {
            nx++;
        } else if(t == 'L') {
            ny--;
        } else if(t == 'R') {
            ny++;
        } else {

        }
        if (nx < 0 || nx >= H || ny < 0 || ny >= W ) continue;
        if (S[nx][ny] == '#') continue;
        X = nx;
        Y = ny;
        if(visit[X][Y]) continue;
        visit[X][Y] = true;
        if(S[X][Y] == '@') ans++;        
    }
    cout << X+1 << " " << Y+1 << " " << ans << endl;
    return 0;
}