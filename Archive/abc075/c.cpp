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
    ll N, M;
    cin >> N >> M;
    vector<ll> U(M),V(M);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        U[i]=u, V[i]=v;
    }
    ll ans = 0;
    rep(i,M) {
        vector D(N, vector<ll>(N,1));
        rep(i,N) D[i][i] = 0;
        rep(j,M){
            if(i==j) continue;
            D[U[j]][V[j]] = D[V[j]][U[j]] = 0;
        }
        rep(k,N)rep(x,N)rep(y,N)chmin(D[x][y], D[x][k]+D[k][y]);
        bool f = true;
        rep(x,N)rep(y,N) if(D[x][y]>0) f=false;
        if(!f) ans++;
    }
    cout<<ans<<endl;
    return 0;
}