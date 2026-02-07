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
    int H = 24;
    mf_graph<int> G(N+H+2);
    int st = N+H;
    int gl = N+H+1;
    rep(j,24) {
        G.add_edge(N+j, gl, M);
    }
    rep(i,N) {
        G.add_edge(st, i, 10);
        string C; cin>>C;
        rep(j,H) {
            if(C[j] == '1') G.add_edge(i, N+j, 1);
        }
    }
    int res = G.flow(st,gl);
    if(res == M*24) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}