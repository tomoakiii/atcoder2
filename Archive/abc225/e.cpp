#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

struct V {
    ll x, y; int i, j;
    ll dist;
    V(ll x=0, ll y=0, int i=-1): x(x), y(y), i(i) {
        dist = x*x + y*y;
    }
    ll cross(const V& a) const { return x*a.y - y*a.x;}
    bool up() const { return y > 0 || (y == 0 && x > 0);}
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
    int st;
    ll mx=0;
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
    rep(i,M) {
        auto q = ps[i];
        if(chmin(mx, q.dist)) st = i;
        if(q.x == 0 && q.y > 0 && q.j == 0) {
            pos[q.i][0] = i+M;
        } else {
            pos[q.i][q.j] = i;
        }
    }

    vector<bool> visit(N,3);
    ll ans = 0;
    multiset<ll> st;
    ll cur = INF;
    for(int i = st; i < st + M; i++) {
        auto q = ps[i];
        if(visit[i] == 3 && q.dist < cur) {
            ans++;
        }
        visit[i]--;
        if()
    }

    return 0;
}