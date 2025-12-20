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
    vector<ll> P(N);
    rep(i,N) {
        cin>>P[i]; P[i]--;
    }
    vector<bool> visit(N);
    vector<vector<int>> loop{};

    auto dfs = [&](auto dfs, int cur, int id)->void{
        if(visit[cur]) return;
        visit[cur] = true;
        loop[id].push_back(cur);
        dfs(dfs, P[cur], id);
    };
    rep(i,N) {
        if(visit[i]) continue;
        loop.push_back({});
        dfs(dfs, i, loop.size() - 1);
    }
    ll ans = 0;
    for(auto lp: loop) {
        ll sz = lp.size();
        if(sz < 2) continue;
        ans += (sz) * (sz-1) / 2;
    }
    cout << ans << endl;
    return 0;
}