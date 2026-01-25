#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

struct V {
    ll x, y; int i, j;
    V(ll x=0, ll y=0, int i=-1): x(x), y(y), i(i) {}
    ll cross(const V& a) const { return x*a.y - y*a.x;}
    bool up() const { return y > 0 || (y == 0 && x > 0);}
    ll dist() {
        return x*x + y*y;
    }
    bool operator<(const V& a) const {
    if (up() != a.up()) return up();
    return cross(a) > 0;
    }
};

typedef pair<ll,int> pli;
int main() {
    ll N; cin>>N;
    vector<V> ps;
    int dy[] = {0, 0, -1};
    int dx[] = {-1, 0, 0};

    priority_queue<pli, vector<pli>, greater<pli>> que;
    rep(i,N) {
        V p;
        cin >> p.x >> p.y, p.i = i;
        rep(k,3) {
            auto q = p;
            q.j = k;
            q.x += dx[k];
            q.y += dy[k];
            ps.push_back(q);
        }
    }
    vector<bool> ans(N);
    int M = ps.size();
    sort(ps.begin(), ps.end());
    vector pos(N, vector<int>(3));
    rep(i,3*N) {
        if(!visit[ps[i].i]) que.push({ps[i].dist, ps[i].i});
        pos[ps[i].i][ps[i].j] = i;
    }
    while(!que.empty()) {
        auto [d, j] = que.top();
        que.pop();
        int i = ps[j].i;
        int nx = (i+1)%M;
        while(ps[i].cross(ps[nx]))



    }

    return 0;
}