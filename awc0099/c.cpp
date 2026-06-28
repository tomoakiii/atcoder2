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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector uv(N, vector<ll>{});
    rep(i,N-1) {
        int p; cin>>p; p--;
        uv[p].emplace_back(i+1);
    }
    vector<ll> D(N);
    rep(i,Q) {
        ll x,d; cin>>x>>d;
        x--;
        D[x] += d;
    }
    auto dfs = [&](auto dfs, int cur)->void{
        for(auto nx:uv[cur]) {
            D[nx] += D[cur];
            dfs(dfs, nx);
        }
    };
    dfs(dfs,0);
    rep(i,N) {
        cout<<D[i]<<" \n"[i==N-1];
    }
    return 0;
}