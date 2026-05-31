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
    vector<bool> skill(N, false);
    queue<int> que;
    rep(i,N) {
        int u,v;
        cin>>u>>v;
        if(u==0 && v==0) {
            skill[i] = true;
            que.push(i);
            continue;
        }
        u--, v--;
        uv[u].emplace_back(i);
        uv[v].emplace_back(i);
    }
    while(!que.empty()) {
        auto q = que.front();
        que.pop();        
        for(auto nx:uv[q]) {
            if(skill[nx]) continue;
            skill[nx] = true;
            que.push(nx);
        }
    }

    ll ans = 0;
    for(auto s: skill) if(s) ans++;
    cout << ans << endl;
    return 0;
}