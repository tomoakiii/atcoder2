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
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    int dy[] = {0,0,1,-1};
    int dx[] = {1,-1,0,0};
    vector T = S;
    for(auto &t:T) for(auto &c:t) c='.';

    rep(i,H) rep(j,W) {
        if(S[i][j] != '#') continue;
        rep(k,4) {
            int ny = i+dy[k];
            int nx = j+dx[k];
            if(ny<0 || ny>=H || nx<0 || nx>=W) continue;
            if(S[ny][nx] == '#') T[i][j] = T[ny][nx] = '#';
        }
    }
    rep(i,H) if(S[i]!=T[i]) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}