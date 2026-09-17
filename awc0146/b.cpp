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
    ll G[2001][2001];
    //vector G(H,vector<ll>(W));
    rep(i,H)rep(j,W)cin>>G[i][j];
    vector<ll> sH(H),sW(W);
    rep(i,H)rep(j,W){
        sH[i]+=G[i][j];
        sW[j]+=G[i][j];
    }
    ll ans = -INF;
    rep(i,H)rep(j,W){
        chmax(ans, sH[i]+sW[j]-G[i][j]);
    }
    cout<<ans<<endl;
    return 0;
}