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
    ll N, Q, R;
    cin >> N >> Q >> R;
    ll M=N-1;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector cnt(N, vector<ll>(R+1));
    ll ans=0;
    while(Q--){
        int c; cin>>c; c--;

        auto dfs = [&](auto self, int cur, int rem, int pre)->void{
            if(cnt[cur][rem] > 1) return;
            rep(i,rem+1) cnt[cur][i]++;
            if(cnt[cur][0] == 1) ans++;
            if(cnt[cur][0] == 2) ans--;
            if(rem==0) return;
            for(auto nx:uv[cur]){
                if(nx==pre)continue;
                self(self, nx, rem-1, cur);
            }
        };

        dfs(dfs, c, R, -1);
        cout<<ans<<endl;
    }
    return 0;
}