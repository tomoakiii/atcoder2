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
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<pair<int,int>>{});
    rep(i,M) {
        int u,v;
        int c;
        cin>>u>>v>>c;
        u--, v--;
        uv[u].emplace_back(v,c);
    }
    vector dist(N, vector<pair<ll,int>>(2, {INF,-1}));
    typedef tuple<ll, int, int> ti; // dist, node, last color
    priority_queue<ti, vector<ti>, greater<ti>> que;
    auto push = [&](int d, int n, int c)->void{
        if(dist[n][1].first <= d) return;
        int tgt = 1;
        if(dist[n][1].second == c) {
            if(dist[n][1].first <= d) return;
            else tgt = 1;
        } else if(dist[n][0].second == c) {
            if(dist[n][0].first <= d) return;
            else tgt = 0;
        } else {
            if(dist[n][1].first <= d) return;
            else tgt = 1;
        }
        que.push(make_tuple(d,n,c));
        dist[n][tgt] = {d, c};
        sort(dist[n].begin(),dist[n].end());
    };
    push(0,0,-1);

    while(!que.empty()){
        auto [d, n, lc] = que.top();
        que.pop();
        bool flg = false;
        rep(k,2) if(dist[n][k].first == d && dist[n][k].second == lc) flg = true;
        if(!flg) continue;

        for(auto [nx, c] : uv[n]){
            if(lc == c) continue;
            push(d+1, nx, c);
        }
    }
    ll ans = INF;
    rep(k,2) chmin(ans, dist[N-1][k].first);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}