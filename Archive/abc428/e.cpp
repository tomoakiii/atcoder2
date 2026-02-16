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
    typedef pair<int,int> pii;
    vector<pii> ans(N);
    auto func = [&](auto func, int st, int d, int cur, int pre=-1)->pii{
        ans[cur] = max(ans[cur], pii(d, st));
        pii ret = {d, cur};
        for(auto nx: uv[cur]) {
            if(nx == pre) continue;
            ret = max(ret, func(func, st, d+1, nx, cur));
        }
        return ret;
    };
    pii a = func(func, 0, 0, 0);
    pii b = func(func, a.second, 0, a.second);
    func(func, b.second, 0, b.second);
    for(auto [i,v]:ans) cout<<1+v<<endl;
    return 0;
}