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

    vector<bool> visit(N), visit2(N);    
    int mx = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    for(auto nx: uv[0]){        
        visit[nx] = true;
        que.push(nx);
    }
    vector<int> ans(N, -1);
    visit2[0] = true;
    ans[0] = que.size();
    visit[0] = true;
    int last = -1;
    int fin = 0;
    while(!que.empty()) {
        auto q = que.top();
        que.pop();        
        for(auto nx: uv[q]){
            if(visit[nx]) continue;
            visit[nx] = true;
            que.push(nx);
        }
        visit2[q] = true;
        chmax(mx, q);
        if(fin < q-1) ans[q] = -1;
        else {
            for(int i = q; i <= mx; i++) {
                if(!visit2[i]) break;                
                fin = i;
                if(i==mx) ans[i] = que.size();
            }
        }
    }

    
    rep(i, N) {
        cout << ans[i] << endl;
    }

    return 0;
}
