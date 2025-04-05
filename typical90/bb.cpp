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
    vector belong(N, vector<ll>{});
    vector<unordered_set<ll>> group(M);
    queue<pair<ll, ll>> que;
    que.push({0, 0});
    rep(i,M) {
        ll K;
        cin >> K;
        rep(k,K) {
            ll r;
            cin >> r;
            r--;
            belong[r].emplace_back(i);
            group[i].insert(r);
        }
    }
    vector<ll> ans(N, -1);
    ans[0] = 0;
    while(!que.empty()) {
        auto [q, t] = que.front();        
        que.pop();
        for (auto b: belong[q]){
            while(group[b].size() > 0) {
                auto g = *(group[b].begin());
                if(ans[g] == -1) {                    
                    que.push({g, t+1});
                    ans[g] = t+1;
                }
                group[b].erase(g);
            }
        }
    }
    rep(i,N) printf("%lld\n", ans[i]);
    return 0;
}