#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N;
    cin >> N;
    vector P(N, vector<pair<int, ll>>{});
    ll sm = 0;
    rep(i, N-1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        P[a].push_back({b, c});
        P[b].push_back({a, c});
        sm += c;
    }

    ll mdist=0;
    int mp;
    auto dfs = [&](auto dfs, int cur, int from, ll dist)->void{
        if (mdist<dist){
            mdist = dist;
            mp = cur;
        }
        for(auto [p, d]:P[cur]){
            if (p==from) continue;
            dfs(dfs, p, cur, dist+d);
        }
    };
    dfs(dfs, 0,-1,0);
    mdist=0;
    int mp1=mp;
    dfs(dfs, mp1, -1, 0);
    int mp2=mp;
    vector<int> dep(N);
    auto dfs2 = [&](auto dfs2, int cur, int from, ll dist)->void{
        dep[cur] = dist;
        for(auto [p, d]:P[cur]){
            if (p==from) continue;
            dfs2(dfs2, p, cur, dist+1);
        }
    };
    dfs2(dfs2, mp1, -1, 0);
    ll ans=0;
    auto dfs3 = [&](auto dfs3, int cur, int from, bool mway)->void{
        for(auto [p, d]:P[cur]){
            if (p==from) continue;
            if(mway) {
                if(dep[p] == dep[cur]-1) {
                    ans += d;
                    dfs3(dfs3, p, cur, true);
                } else {
                    ans += 2*d;
                    dfs3(dfs3, p, cur, false);
                }
            } else {
                ans += 2*d;
                dfs3(dfs3, p, cur, false);
            }
        }
    };
    dfs3(dfs3, mp2, -1, true);
    cout << ans << endl;
    return 0;
}