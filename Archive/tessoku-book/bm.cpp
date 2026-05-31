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
typedef pair<ll, int> pli;
int main(){
    ll N;
    cin >> N;
    vector uv(N, vector<int>{});
    rep(i,N-1) {
        int v; cin>>v; v--;
        uv[v].push_back(i+1);
    }
    vector<int> ans(N);
    auto dfs = [&](auto dfs, int cur, int pre=-1)->int{
        int sm = 1;
        for(auto nx: uv[cur]) {
            if(nx == pre) continue;
            sm += dfs(dfs, nx, cur);
        }
        ans[cur] = sm - 1;
        return sm;
    };
    dfs(dfs, 0);
    rep(i,N) cout << ans[i] << " ";
    cout << endl;
    return 0;
}