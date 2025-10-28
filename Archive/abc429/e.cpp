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
typedef pair<int, int> pii;
typedef pair<ll, pii> pli;

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
    string S; cin>>S;
    vector dist(N, vector<pair<ll,int>>(2, {INF,-1})); // dist[i] = d, from    
    queue<pli> que;
    rep(i,N) {
        if(S[i] == 'S') {
            for(auto nx: uv[i]) {
                if(dist[nx][1].first == 1) continue;
                if(dist[nx][0].first > 1) {
                    dist[nx][0] = {1,i};                        
                } else {
                    dist[nx][1] = {1,i};                        
                }
                que.push({1, {i, nx}});
            }
        }
    }
    while(!que.empty()) {
        auto [d, fromto] = que.front();
        auto [from, to] = fromto;
        que.pop();
        if(dist[to][1].first < d) continue;        
        for(auto nx: uv[to]) {
            if(dist[nx][1].first <= d+1) continue;
            if(dist[nx][0].second == from || dist[nx][1].second == from) continue;
            if(dist[nx][0].first <= d+1) {
                dist[nx][1] = {d+1, from};
            } else {
                dist[nx][1] = dist[nx][0];
                dist[nx][0] = {d+1, from};
            }            
            que.push({d+1, {from, nx}});
        }
    }

    rep(i,N) {
        if(S[i]=='S') continue;
        cout << dist[i][0].first+dist[i][1].first<<endl;
    }
    return 0;
}