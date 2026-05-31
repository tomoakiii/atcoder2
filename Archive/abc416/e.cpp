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
    ll N,M;
    cin >> N >> M;
    vector dist(N+1, vector<ll>(N+1, INF));
    rep(i,N+1) dist[i][i] = 0;
    rep(i,M) {
        int a,b; ll c; cin>>a>>b>>c;
        a--,b--;
        chmin(dist[a][b], c);
        chmin(dist[b][a], c);
    }
    ll K,T; cin>>K>>T;
    vector<int> D(K);
    rep(i,K) {
        cin>>D[i];
        D[i]--;
    }
    rep(i,K) {
        chmin(dist[N][D[i]], T);
        chmin(dist[D[i]][N], 0ll);
    }
    rep(k,N+1) rep(i,N+1) rep(j,N+1) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }
    
    ll Q; cin>>Q;
    auto update = [&](int x, int y, ll t)->void{
            if(dist[x][y] <= t) return;
            rep(i,N+1) rep(j,N+1) chmin(dist[i][j], dist[i][x] + t + dist[y][j]);            
    };

    while(Q--){
        int Qt; cin>>Qt;
        if(Qt == 1)  {
            int x, y; ll t; cin>>x>>y>>t;
            x--, y--;            
            update(x, y, t);
            update(y, x, t);
        } else if (Qt == 2) {
            int x; cin>>x;
            x--;            
            update(N, x, T); update(x, N, 0);            
        } else {
            ll ans = 0;
            rep(i,N) rep(j,N) {
                ans += (dist[i][j] == INF)?0:dist[i][j];        
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}