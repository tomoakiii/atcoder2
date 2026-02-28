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
    cin >> H >> W;
    vector G(H, vector<ll>(W));
    int dx[] = {1, 0};
    int dy[] = {0, 1};

    vector<tuple<ll,ll,ll,ll>> ans;
    rep(i,H) rep(j,W) cin>>G[i][j];
    rep(i,H) rep(j,W){
        if(G[i][j]%2==0) continue;
        rep(k,2) {
            int ny = i+dy[k];
            int nx = j+dx[k];
            if(nx<0 || ny<0 || ny>=H || nx>=W) continue;
            G[ny][nx]++; G[i][j]--;
            ans.push_back(make_tuple(i+1,j+1,ny+1,nx+1));
            break;
        }
    }
    cout<<ans.size()<<endl;
    for(auto [i,j,y,x]:ans) {
        cout<<i<<" "<<j<<" "<<y<<" "<<x<<endl;
    }
    return 0;
}