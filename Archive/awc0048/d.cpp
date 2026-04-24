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
    int H,W,K; cin>>H>>W>>K;
    vector<string> S(H);
    rep(i,H)cin>>S[i];
    vector G(H+1,vector<ll>(W+1));
    rep(i,H) {
        rep(j,W) {
            G[i+1][j+1]=S[i][j]-'0';
        }
    }
    rep(i,H+1) rep(j,W) G[i][j+1]+=G[i][j];
    rep(i,H) rep(j,W+1) G[i+1][j]+=G[i][j];
    ll ans=-1;
    for(int k=1; k<=K; k++) {
        if(K%k != 0) continue;
        int m=K/k;
        for(int i=k;i<=H;i++){
            for(int j=m;j<=W;j++){
                chmax(ans, G[i][j] + G[i-k][j-m] - G[i][j-m] - G[i-k][j]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}