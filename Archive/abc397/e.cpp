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
    ll N, K;
    cin >> N >> K;
    vector uv(N*K, vector<ll>{});
    rep(i,N*K - 1) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> debug(N*K, -1);
    bool fl = true;
    auto f = [&](auto f, int cur, int pre) -> ll{
        vector<ll> path{};
        for(auto nx: uv[cur]) {
            if (nx == pre) continue;
            ll p = f(f, nx, cur);
            if(p == 0) continue;            
            path.push_back(p);                       
        }
        ll sm = 0;
        if(path.size() > 2) {
            fl = false;
        } else if(path.size() == 2) {            
            sm = path[0] + path[1] + 1;
            if(sm < K){
                fl = false;
            }
        } else if (path.size() == 1) {
            sm = path[0] + 1;
        } else {
            sm = 1;
        }
        if(sm > K) {
            fl = false;
        }
        if(sm == K) sm = 0;
        debug[cur] = sm;
        return sm;
    };
    if(f(f, 0, -1) != 0) fl = false;
    if(fl)    cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}