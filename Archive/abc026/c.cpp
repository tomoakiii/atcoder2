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
    vector uv(N, vector<int>{});
    rep(i,N-1) {
        int u;cin>>u;u--;
        uv[u].emplace_back(i+1);
    }
    auto dfs= [&](auto dfs, int cur, int pre)->ll{
        ll ret = 1;
        if(uv[cur].empty()) {
            return 1;
        }
        ll mx=0, mn=INF;
        for(auto nx: uv[cur]) {
            if(nx == pre) continue;
            ll s = dfs(dfs, nx, cur);
            chmax(mx,s);
            chmin(mn,s);
        }
        ret += mx + mn;
        return ret;
    };

    cout << dfs(dfs, 0, -1) << endl;
    return 0;
}