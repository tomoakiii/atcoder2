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
    vector uv(N, vector<bool>(N,false));

    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u][v] = true;
        uv[v][u] = true;
    }
    ll ans = 0;
    auto dfs = [&](auto dfs, int cur, ll state) -> void{
        if(cur==N) {
            ll cnt = 0;
            rep(i,N) if(state>>i & 1) cnt++;
            chmax(ans, cnt);
            return;
        }
        bool f = true;
        for(int k=0; k<cur; k++) {
            if(state>>k & 1) if(!uv[k][cur]) f = false;
        }
        if(f) dfs(dfs, cur+1, state|(1<<cur));
        dfs(dfs, cur+1, state);
    };
    dfs(dfs, 0, 0);
    cout << ans << endl;
    return 0;
}