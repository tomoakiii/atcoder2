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
typedef modint1000000007 mint;
int main(){
    ll N, a,b,M;
    cin >> N >> a>>b>>M;
    a--,b--;
    vector uv(N, vector<int>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].push_back(v);
        uv[v].push_back(u);
    }
    queue<int> que;
    vector<bool> visit(N);
    vector<ll> dist(N,INF);
    dist[a] = 0;
    visit[a] = true;
    que.push(a);
    while(!que.empty()) {
        auto q = que.front();
        que.pop();
        for(auto nx: uv[q]) {
            if(visit[nx]) continue;
            if(dist[nx] <= dist[q] + 1) continue;
            dist[nx] = dist[q] + 1;
            que.push(nx);
        }
    }
    vector ORD(N, vector<int>{});
    rep(i,N) {
        ORD[dist[i]].push_back(i);
    }
    vector<mint> dp(N);
    dp[a] = 1;
    for(auto oo: ORD) {
        for(auto cur: oo) {
            for(auto nx: uv[cur]) {
                if(dist[nx] == dist[cur]+1) dp[nx] += dp[cur];
            }
        }
    }
    cout << dp[b].val() << endl;
    return 0;
}