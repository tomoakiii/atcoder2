// Typical90-021, Count pairs of Each-reachable-nodes
// https://atcoder.jp/contests/typical90/tasks/typical90_u
// https://x.com/e869120/status/1385363292739104775/photo/1


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
    int N, M;
    cin >> N >> M;    
    vector uv(N, vector<int>{}), vu(N, vector<int>{});

    rep(i,M){
        int u, v;
        cin >> u >> v;
        u--, v--;
        uv[u].emplace_back(v);
        vu[v].emplace_back(u);
    }

    vector<bool> visit(N, false);
    vector<pair<int, int>> idx(N, {0, 0});
    int id = 0;
    auto f = [&](auto f, int cur)->void{
        visit[cur] = true;
        for(auto nx: uv[cur]) {
            if (visit[nx]) continue;
            f(f, nx);
        }
        idx[cur] = {id++, cur};
    };

    // 1st dsu --> index incresing at returning
    rep(i, N) {
        if(visit[i] != 0) continue;
        f(f, i);
    }

    // decrease sort
    sort(idx.rbegin(), idx.rend());

    // use v->u arrows
    int grp = 0;
    map<int, ll> mp;
    vector<bool> visit2(N, false);
    auto f2 = [&](auto f2, int cur)->void{        
        visit2[cur] = true;
        mp[grp]++;
        for(auto nx: vu[cur]) {
            if (visit2[nx]) continue;
            f2(f2, nx);
        }      
    };
    

    // 2nd dsu --> grouping with reachable nodes
    for(auto [id, i] : idx) {
        if(visit2[i]) continue;
        f2(f2, i);
        grp++;
    }
    ll ans = 0;
    for(auto m: mp) {
        ans += m.second * (m.second-1) / 2;
    }
    cout << ans << endl;
    return 0;
}