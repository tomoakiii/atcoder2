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
typedef pair<ll,int> pli;

int main() {
    int N,M; cin>>N>>M;
    vector uv(N, deque<tuple<int,int,int>>{});
    rep(i,M) {
        int a,b,c,d; cin>>a>>b>>c>>d;
        a--,b--;
        uv[a].push_back(make_tuple(b,c,d));
        uv[b].push_back(make_tuple(a,c,d));
    }

    vector<ll> dist(N, INF);
    vector<ll> score(N, INF);
    vector<ll> tree(N, INF);

    dist[0] = 0;
    score[0] = 0;
    tree[0] = 0;

    priority_queue<pli,vector<pli>,greater<pli>> que;
    que.push({0,0});

    while(!que.empty()) {
        auto [sc, cur] = que.top();
        que.pop();
        if(score[cur] < sc) continue;
        for(auto [nx, c, d] : uv[cur]) {
            if(score[nx] <= sc + c*N - d) continue;
            score[nx] = sc + c*N - d;
            dist[nx] = dist[cur] + c;
            tree[nx] = tree[cur] + d;
            que.push({score[nx], nx});
        }
    }
    cout << dist[N-1] << " " << tree[N-1] << endl;
}