//https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bp
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

int main() {
    int N,M;
    cin>>N>>M;
    mf_graph<int> G(N);
    rep(i,M) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G.add_edge(u, v, c);
    }
    int res = G.flow(0, N-1);
    cout << res << endl;
}