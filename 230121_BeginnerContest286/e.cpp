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
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<string> S(N);
    struct node{
        ll s;
        int d;
        node (ll ss, int dd): s(ss), d(dd) {}
        operator<(const node *x){
        if (x.d == d) {
            return (s > x.s);
        } else {
            return (d < x.d);
        }
      }  
    };
    vector dist(N, vector<node>(N));
    rep(i,N) {
        dist[i][i] = node(A[i], 0);
    }
    rep(i,N) rep(j,N) {
        if (S[i][j] == 'N') {
            dist[i][j] = dist[j][i] = node(A[i]+A[j], 1);
        }
    }
    rep(k,N) rep(i,N) rep(j,N) {
        chmin(dist[i][j], dist[i][k]+dist[k][j]);
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << dist[u][v].d << " " << dist[u][v].s << endl;
    }
    return 0;
}