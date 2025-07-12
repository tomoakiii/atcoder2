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
    ll N, Q;
    cin >> N >> Q;
    vector uv(N, vector<ll>{});
    int M = N-1;
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<int> dist(N, -1);
    auto f = [&](auto f, int cur, int d)->void{
        dist[cur] = d;
        for(auto nx : uv[cur]) {
            if(dist[nx] > -1) continue;
            f(f, nx, d+1);
        }
    };
    f(f, 0, 0);
    while(Q--) {
        int c,d; cin>>c>>d; c--,d--;
        if(abs(dist[c]-dist[d])%2 == 0) cout<<"Town"<<endl;
        else cout<<"Road"<<endl;
    }
    return 0;
}