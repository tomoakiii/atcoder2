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
    ll N,M,Q;
    cin >> N >> M >> Q;
    vector G(N+1,vector<ll>(M+1));
    vector B(N,vector<ll>(M));

    rep(i,N)rep(j,M)cin>>B[i][j];
    rep(i,Q){
        ll r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;
        r1--,c1--;
        G[r1][c1]++;
        G[r2][c2]++;
        G[r1][c2]--;
        G[r2][c1]--;
    }
    rep(i,N)rep(j,M+1) G[i+1][j]+=G[i][j];
    rep(i,N+1)rep(j,M) G[i][j+1]+=G[i][j];
    ll ans=0;
    rep(i,N)rep(j,M){
        if(G[i][j]%2==1)ans+=2*B[i][j];
        else ans+=B[i][j];
    }
    cout<<ans<<endl;
    return 0;
}