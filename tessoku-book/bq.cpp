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
    int N;;
    cin>>N;
    mf_graph<int> G(2*N+2);
    for(int i=1; i<=N; i++) {
        G.add_edge(0, i, 1);
        G.add_edge(i+N, N+N+1, 1);
        string C; cin>>C;
        rep(j,N) {
            if(C[j] == '#') G.add_edge(i, j+N+1, 1);
        }
    }
    int res = G.flow(0, N+N+1);
    cout << res << endl;
}