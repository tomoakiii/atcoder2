#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using P = pair<ll, ll>;

template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
//void chmax(ll& x, ll y) {x = max(x, y);}

int main(){
    ll N, M;
    cin >> N >> M;
    vector dist(N, vector<ll>(N, INF));
    vector<ll> U(M), V(M);
    vector<ll> T(M);
    rep(i,M) {
        ll u,v,t;
        cin >> u >> v >> t;
        u--, v--;
        U[i] = u, V[i]  = v, T[i] = t;        
        chmin(dist[u][v], t);
        chmin(dist[v][u], t);
    }
    rep(i, N) dist[i][i] = 0;
    rep(k, N) rep(i, N) rep(j, N) {chmin(dist[i][j], dist[i][k] + dist[k][j]);}
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
        ll mn = INF;
        do{            
            rep(t, 1<<K){
                int st = 0;
                ll d=0;
                int s, g;
                rep(i,K) {
                    g = U[B[i]], s = V[B[i]];
                    if(t>>i&1) swap(g,s);
                    d += dist[st][s];
                    d += T[B[i]];
                    st = g;
                }
                d += dist[g][N-1];
                chmin(mn, d);
            }
        }while (next_permutation(B.begin(), B.end()));        
        cout << mn << endl;
    }
    return 0;
}