#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using P = pair<ll, ll>;

int main(){
    ll N, M;
    cin >> N >> M;
    vector dist(N, vector<ll>(N, INF));
    vector brd(N, vector<P>{});
    vector<ll> U(M), V(M);
    vector<ll> T(M);
    rep(i,M) {
        ll u,v,t;
        cin >> u >> v >> t;
        u--, v--;
        U[i] = u, V[i]  = v, T[i] = t;
        brd[u].push_back({t, v});
        brd[v].push_back({t, u});
    }
    // rep(i,N) sort(brd[i].begin(), brd[i].end());
    struct node{
        int from;
        int to;
        ll d;
        bool operator<(const node& x) const{
            return (d < x.d);
        }
    };
    rep(stt, N){        
        dist[stt][stt] = 0;
        priority_queue<node> que;
        node n;
        for (auto q: brd[stt]) {
            n.from = stt;
            n.to = q.second;
            n.d = q.first;
            que.push(n);
        }
        while (!que.empty()){
            auto q = que.top();
            que.pop();            
            if (dist[stt][q.to] > dist[stt][q.from] + q.d) {
                dist[stt][q.to] = dist[stt][q.from] + q.d;
                for (auto q2: brd[q.to]) {
                    n.from = q.to;
                    n.to = q2.second;
                    n.d = q2.first;
                    que.push(n);
                }
            }
        }
    }
    ll Q;
    cin >> Q;
    while (Q--) {
        ll K;
        cin >> K;
        vector<ll> B(K);
        rep (i,K) {
            cin >> B[i];
            B[i]--;
        }
        vector<bool> visit(K, false);
        int stt = 0;
        ll ans = 0;
        
        int ind;
        int gl;
        int ii;
        rep (j,K) {
            ll mdin = INF;  
            rep (i,K) {
                if (visit[i]) continue;
                if (mdin > dist[stt][U[B[i]]]) {
                    mdin = dist[stt][U[B[i]]];
                    gl = V[B[i]];
                    ii = i;
                    ind = B[i];
                }
                if (mdin > dist[stt][V[B[i]]]) {
                    mdin = dist[stt][V[B[i]]];
                    gl = U[B[i]];
                    ii = i;
                    ind = B[i];
                }
            }
            ans += mdin;
            stt = gl;            
            ans += T[ind];
            visit[ii] = true;
        }
        ans += dist[gl][N-1];
        cout << ans << endl;
    }
    return 0;
}