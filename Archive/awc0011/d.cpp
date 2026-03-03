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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> V(N);
    vector uv(N, vector<int>{});
    rep(i,N) cin>>V[i];
    rep(i,N-1) {
        int p; cin>>p; p--;
        uv[i+1].push_back(p);
        uv[p].push_back(i+1);
    }
    vector<ll> ans(N);
    auto dfs = [&](auto dfs, int cur, int pre)->void{
        if(pre!=-1) ans[cur] = ans[pre]+V[cur];
        else ans[cur] = V[cur];
        for(auto nx: uv[cur]) {
            if(nx == pre) continue;
            dfs(dfs, nx, cur);
         }
    };
    dfs(dfs, 0, -1);
    while(Q--) {
        int x; cin>>x; x--;
        cout<<ans[x]<<endl;
    }
    return 0;
}