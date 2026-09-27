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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    vector dist(N, vector<ll>(N,INF));
    rep(i,M){
        int u,v; ll w;
        cin>>u>>v>>w;
        u--,v--;
        dist[u][v]=w;
    }
    rep(k,N)rep(i,N)rep(j,N)chmin(dist[i][j],dist[i][k]+dist[k][j]);
    vector<ll> ans(N);
    rep(i,N)rep(j,N){
        if(dist[i][j]==INF)continue;
        if(i==j)continue;
        rep(k,N){
            if(k==i || k==j) continue;
            if(dist[i][j] == dist[i][k]+dist[k][j]) ans[k]++;
        }
    }
    rep(i,N)cout<<ans[i]<<"\n";
    return 0;
}