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

    ll N, M;
    cin >> N >> M;
    vector uv(N+1, vector<ll>{});
    vector vu(N+1, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        uv[u].emplace_back(v);
        vu[v].emplace_back(u);
    }
    dsu UF(N+1);
    unordered_set<int> del;
    vector<unordered_set<int>> stock(N+1);
    ll ans = uv[1].size();
    for(auto nx:uv[1]) {
        if(nx==1) continue;
        stock[nx].insert(1);
        del.insert(nx);
    }
    UF.merge(0,1);
    cout << del.size() << endl;
    int reachable = 0;
    vector<bool> isr(N+1);
    for(int i=2; i<=N; i++) {
        while(!stock[i].empty()) {
            int pre = *stock[i].begin();
            stock[i].erase(pre);
            UF.merge(pre, i);
        }
        if(del.contains(i)){
            del.erase(i);
        }
        if(UF.same(0, i)) {
            isr[i] = true;
        } else {
            reachable++;
            isr[i] = false;
        }
        for(auto nx: uv[i]) {
            if(nx > i) {
                if(isr[i] && !del.contains(nx)) del.insert(nx);
                stock[nx].insert(i);
            } else {
                if(!isr[nx] && isr[i]) {
                    UF.merge(nx, i);
                    isr[nx] = true;
                    reachable--;
                }
            }
        }

        if(reachable==0) cout << del.size() << endl;
        else cout << -1 << endl;
    }
    return 0;
}
