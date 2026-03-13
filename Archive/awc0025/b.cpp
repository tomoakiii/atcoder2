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
    ll H,W,N;
    cin >> H >> W >> N;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    string T; cin>>T;
    int y=0, x=0;
    map<char, pair<int,int>> mx;
    mx['U'] = {-1,0};
    mx['D'] = {1,0};
    mx['L'] = {0,-1};
    mx['R'] = {0,1};
    ll ans = 0;
    rep(i,H) rep(j,W) if(S[i][j]=='#')ans++;
    if(S[0][0]=='#')ans--;
    S[0][0]='.';
    rep(i,N) {
        auto [dy,dx] = mx[T[i]];
        int ny = y+dy;
        int nx = x+dx;
        // cerr<<ny<<" "<<nx<<endl;
        if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
        if(S[ny][nx]=='#') {
            ans--;
            S[ny][nx] = '.';
        }
        y=ny; x=nx;
    }
    cout<<ans<<endl;
    return 0;
}