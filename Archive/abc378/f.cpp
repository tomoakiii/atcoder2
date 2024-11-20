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
    vector uv(N, vector<ll>{});
    rep(i,N-1) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    
    ll ans = 0;
    vector<ll> dp(N, 0);
    auto f = [&](auto f, int cur, int pre) -> void{        
        for(auto nx: uv[cur]){
            if (nx == pre) continue;
            f(f, nx, cur);                
            if (uv[cur].size() == 2) {
                dp[cur] = 1;
                ans += dp[nx];
            }
            if (uv[cur].size() == 3) {
                if(dp[cur] > 0) {
                    ans += dp[cur] * dp[nx];
                }
                dp[cur] += dp[nx];
            }
        }    
    };

    f(f, 0, -1);
            
    rep(i,N) {
        for(int j: uv[i]) {
            if(i>=j) continue;
            if(uv[i].size() == 2 && uv[j].size() == 2) ans--;
        }
    }
    cout << ans << endl;
    return 0;
}