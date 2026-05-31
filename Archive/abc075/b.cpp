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
    vector<string>S(H);
    rep(i,H) cin>>S[i];
    int dx[]={-1,0,1,1,1,0,-1,-1};
    int dy[]={1,1,1,0,-1,-1,-1,0};
    rep(i,H) {
        rep(j,W) {
            if(S[i][j] == '#') continue;
            int cnt = 0;
            rep(k,8) {
                int ny = i+dy[k];
                int nx=j+dx[k];
                if(nx<0||nx>=W||ny<0||ny>=H) continue;
                if(S[ny][nx] == '#') cnt++;
            }
            S[i][j] = '0' + cnt;
        }
    }
    rep(i,H) cout<<S[i]<<endl;
    return 0;
}