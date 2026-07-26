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
    ll N;
    cin >> N;
    vector uv(N, vector<ll>{});
    rep(i,N-1) {
        int u;
        cin>>u;
        u--;
        uv[u].emplace_back(i+1);
    }
    vector<ll> V(N);
    rep(i,N) cin>>V[i];
    auto dfs = [&](auto self, int v) -> ll {
        ll res = 0;
        for (auto u : uv[v]) {
            res += self(self, u);
        }
        if(V[v] < res) {
            cout << "No" << endl;
            exit(0);
        }
        return V[v];
    };
    dfs(dfs, 0);
    cout << "Yes" << endl;
    return 0;
}