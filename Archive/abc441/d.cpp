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
    ll N, M, L, S, T;
    cin >> N >> M >> L >> S >> T;
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        u--, v--;
        uv[u].emplace_back(v,c);
    }
    vector<bool> ans(N, false);
    auto func = [&](auto func, int cur, int l, ll cost) -> void{
        if(l == L) {
            if(S<=cost && cost<=T) ans[cur] = true;
            return;
        }
        for(auto [nx, c]: uv[cur]) {
            func(func, nx, l+1, cost+c);
        }
    };
    func(func, 0, 0, 0);
    rep(i,N) if(ans[i]) cout<<i+1<<endl;
    return 0;
}