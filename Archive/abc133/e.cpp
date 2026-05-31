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
typedef modint1000000007 mint;
int main(){
    ll N, M, K;
    cin >> N >> K;
    M = N - 1;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    vector<ll> pre(N,-1);
    vector<bool> visit(N);
    vector<ll> cnt(N);
    mint ans = 1;
    auto func = [&](auto func, int cur, int nm, int d) -> void{
        visit[cur] = true;
        if(nm > K) nm = K;
        ans *= (K - nm);
        int nmc = 1;
        if(d >= 1) nmc++;
        for(auto nx: uv[cur]) {
            if(visit[nx]) continue;            
            func(func, nx, nmc, d+1);
            nmc++;
        }
    };
    func(func, 0, 0, 0);
    cout << ans.val() << endl;
    return 0;
}