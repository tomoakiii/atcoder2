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

int main(){
    ll N, M;
    cin >> N >> M;

    vector visit(N, vector<ll>(N, -1));
    vector<ll> dy, dx;
    for(ll i=0; i<N; i++) {
        for (ll j=i; j<N; j++) {
            ll k = i*i + j*j;
            if (k > M) break;
            if (k == M) {
                dx.emplace_back(i); dy.emplace_back(j);
                dx.emplace_back(j); dy.emplace_back(i);
                dx.emplace_back(-i); dy.emplace_back(j);
                dx.emplace_back(j); dy.emplace_back(-i);
                dx.emplace_back(i); dy.emplace_back(-j);
                dx.emplace_back(-j); dy.emplace_back(i);
                dx.emplace_back(-i); dy.emplace_back(-j);
                dx.emplace_back(-j); dy.emplace_back(-i);
            }
        }
    }

    queue<pair<pii,int>> que;
    visit[0][0] = 0;
    que.push({{0,0}, 0});
    while(!que.empty()) {
        auto [xy, cnt] = que.front();
        auto [x, y] = xy;
        que.pop();
        rep(i, dx.size()) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= N || nx < 0 || ny >= N || ny < 0) continue;
            if(visit[nx][ny] >= 0) continue;
            visit[nx][ny] = cnt+1;
            que.push({{nx, ny}, cnt+1});
        }
    }

    bool ans = true;
    rep(i,N) {
        rep(j,N) cout << visit[i][j] << " ";
        cout << endl;
    }
    return 0;
}