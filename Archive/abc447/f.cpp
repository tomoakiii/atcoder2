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


void solve(){
    ll N, M;
    cin >> N;
    M = N-1;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<bool> visit(N);
    int ans = 1;
    rep(i,N) {
        auto dfs = [&](auto dfs, int cur)->int{
            visit[cur] = true;
            int ret = 0;
            vector<int> cld(3,0);
            for(auto nx:uv[cur]) {
                if(visit[nx])continue;
                cld[2] = dfs(dfs, nx);
                sort(cld.rbegin(), cld.rend());
            }
            if(uv[cur].size() >= 4) chmax(ans, cld[0]+cld[1]+1);
            if(uv[cur].size() == 3) {
                ret = 1;
                chmax(ans, cld[0]+1);
            } else if (uv[cur].size() >= 4) {
                ret = cld[0] + 1;
                chmax(ans, cld[0]+1);
            }
            //cerr << cur << " " << ret << endl;
            return ret;
        };
        if(uv[i].size() == 1) {
            dfs(dfs, i);
            break;
        }
    }
    cout<<ans<<endl;
}


int main(){
    int Q; cin>>Q;
    while(Q--){
        solve();
        //cerr<<endl;
    }
    return 0;
}