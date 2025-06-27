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
    map<pair<int,int>, int> mp;
    vector<pair<int,int>> edge(M);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;        
        uv[u].emplace_back(v);
        edge[i] = {u,v};
        mp[edge[i]] = i;
    }    
    set<pair<int,int>> path;
    auto f = [&](pair<int,int> ng = {-1,-1}, bool flg = false)-> int {
        priority_queue<int, vector<int>, greater<int>> que;
        que.push(0);
        vector<int> dist(N, INFi);
        dist[0] = 0;
        vector<int> par(N, -1);
        while(!que.empty()){
            int q = que.top();
            que.pop();
            for(auto nx: uv[q]) {
                if(dist[nx] <= dist[q] + 1) continue;
                pair<int,int> ft = {q, nx};
                if(ft == ng) continue;
                dist[nx] = dist[q] + 1;
                que.push(nx);
                par[nx] = q;
            }
        }
        if(par[N-1] == -1) return -1;
        int p = N-1;        
        if(flg) {
            while(par[p] != -1) {
                path.insert({par[p], p});
                p = par[p];
            }
        }
        return dist[N-1];
    };
    
    int d = f({-1,-1}, true);
    
    rep(i,M) {
        if(!path.contains(edge[i])) {
            cout << d << endl;
            continue;
        }
        cout << f(edge[i], false) << endl;
    }
    return 0;
}