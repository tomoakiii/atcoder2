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
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    
    int Q;
    cin >> Q;
    while(Q--) {
        int x, k;
        cin >> x >> k;
        x--;
        int sm = 0;
        queue<int> que;
        que.push(x);        
        unordered_map<int, int> visit;
        visit[x] = 0;
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            if(visit[cur] < k) {
                for(auto nx: uv[cur]) {
                    if(visit.contains(nx)) continue;
                    visit[nx] = visit[cur]+1;
                    que.push(nx);
                }
            }
        }        
        for(auto v: visit) sm += v.first+1;
        cout << sm << endl;
    }
    return 0;
}