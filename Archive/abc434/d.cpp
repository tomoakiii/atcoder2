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
    ll N;
    cin >> N;
    ll M = 2000;
    //ll M = 10;
    vector G(M+1, vector<ll>(M+1));
    vector W(M+1, vector<ll>(M+1));
    vector<ll> U(N),D(N),L(N),R(N);
    rep(i,N) {
        ll u,d,l,r;
        cin>>u>>d>>l>>r;
        u--,d--,l--,r--;
        U[i]=u, D[i]=d, L[i]=l, R[i]=r;
        G[u][l]++; G[d+1][r+1]++;
        G[d+1][l]--; G[u][r+1]--;
        W[u][l]+=i; W[d+1][r+1]+=i;
        W[d+1][l]-=i; W[u][r+1]-=i;
    }
    rep(i,M+1) rep(j,M) {
        G[i][j+1] += G[i][j];
        W[i][j+1] += W[i][j];
    }
    rep(i,M) rep(j,M+1) {
        G[i+1][j] += G[i][j];
        W[i+1][j] += W[i][j];
    }
    ll cnt=0;
    vector<ll> ans(N);
    rep(i,M) rep(j,M) {
        if(G[i][j]==0) cnt++;
        if(G[i][j]==1) ans[W[i][j]]++;
    }
    rep(i,N) cout<<cnt+ans[i]<<endl;
    return 0;
}