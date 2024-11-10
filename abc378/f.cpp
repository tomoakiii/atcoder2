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
    auto f = [&](auto f, int cur, int pre) -> ll{
        if (uv[cur].size() == 1) {
            auto nx = uv[cur][0];
            if(nx != pre) f(f, nx, cur);
            return 0;
        }
        if (uv[cur].size() == 2) {
            for(auto nx: uv[cur]){
                if (nx == pre) continue;
                ans += f(f, nx, cur);
            }
            return 1;
        } else {
            ll p[2] = {0,0};
            int ind = 0;
            for(auto nx: uv[cur]){
                if (nx == pre) continue;
                p[ind] = f(f, nx, cur);
                ind++;
            }
            ans += p[0]*p[1];
            return p[0] + p[1];
        }
    };

    rep(i, N-1) {
        if (uv[i].size() == 1) {
            f(f, i, -1);
            break;
        }
    }
    
    cout << ans << endl;    
    return 0;
}