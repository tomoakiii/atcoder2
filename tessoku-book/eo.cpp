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
typedef pair<ll,pair<int,int>> pli;
int main() {
    int N,M; cin>>N>>M;
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    vector uv(N, vector<int>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        uv[u].push_back(v);
    }
    vector route(N, vector<bool>(N));
    vector<pair<ll,int>> score(N);
    ll ans = 0;
    rep(i,N) {
        ll sm = 0;
        vector<int> visit(N,false);
        auto dfs = [&](auto dfs, int cur) -> void{
            sm += P[cur];
            route[i][cur] = true;
            for(auto nx: uv[cur]) {
                if(route[i][nx]) continue;
                dfs(dfs, nx);
            }
        };
        dfs(dfs, i);
        score[i] = {sm, i};
    }
    sort(score.rbegin(), score.rend());
    vector<bool> visit(N);
    for(auto [v, i]: score) {
        if(v<=0) break;
        bool flg = true;
        rep(j,N) {
            if(!route[i][j]) continue;
            if(visit[j]) flg = false;
        }
        if(flg) {
            ans += v;
            rep(j,N){
                if(!route[i][j]) continue;
                visit[j] = true;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}