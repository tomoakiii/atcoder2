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
    ll N, M, E;
    cin >> N >> M >> E;
    vector uv(N+M, vector<ll>{});
    vector<int> U(E), V(E);
    rep(i,E) {
        cin>>U[i]>>V[i];
        U[i]--, V[i]--;
    }
    ll Q;
    cin >> Q;
    vector<int> X(Q);
    vector<bool> cut(E);
    rep(i,Q) {
        cin>>X[i];
        X[i]--;
        cut[X[i]] = true;
    }
    rep(i,E) {
        if(cut[i]) continue;
        int u = U[i], v = V[i];
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    
    reverse(X.begin(), X.end());
    vector<ll> ans(Q);
    ll tans = 0;
    vector<bool> visit(N+M);
    queue<int> que;
    rep(i, M) {
        que.push(N+i);
        visit[N+i] = true;
    }

    rep(i,Q) {
        while(!que.empty()) {
            auto q = que.front();
            que.pop();
            for(auto nx : uv[q]) {
                if (visit[nx]) continue;
                que.push(nx);
                visit[nx] = true;
                tans++;
            }
        }
        ans[i] = tans;
        int u = U[X[i]], v = V[X[i]];
        uv[u].push_back(v);
        uv[v].push_back(u);
        if(visit[u] && !visit[v]) {
            tans++;
            visit[v] = true;
            que.push(v);
        }
        if(!visit[u] && visit[v]) {
            tans++;
            visit[u] = true;
            que.push(u);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto a: ans) cout << a << endl;
    return 0;
}