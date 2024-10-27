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
    vector ab(N, vector<int>{});
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ab[a].emplace_back(b);        
    }

    int ans = INFi;
    vector<int> visit(N, INFi);    
    queue<pair<int, int>> que;
    que.push({0,0});
    while(!que.empty()){
        auto [cur, dpt] = que.front();
        que.pop();            
        visit[cur] = dpt;
        for(auto nx : ab[cur]) {            
            if (nx == 0) {
                chmin(ans, dpt+1);
                break;
            }
            if (visit[nx] < dpt+1) continue;
            que.push({nx, dpt+1});
        }
    };
    
    if (ans == INFi) ans = -1;
    cout << ans << endl;
    return 0;
}