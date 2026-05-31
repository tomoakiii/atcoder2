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
typedef pair<ll, pair<ll,ll>> ppl;
int main(){
    ll N;
    cin >> N;
    vector A(N, vector<ll>(N));
    priority_queue<ppl, vector<ppl>, greater<ppl>> que;
    rep(i,N)rep(j,N) {
        cin>>A[i][j];
        if(i<j)que.push({A[i][j], {i,j}});
    }
    vector D(N, vector<ll>(N,INF));
    rep(i,N) D[i][i] = 0;
    ll ans = 0;
    while(!que.empty()) {
        auto [d, ij] = que.top();
        que.pop();
        auto [i,j] = ij;
        if(D[i][j] > d) {
            ans += d;
            D[i][j] = d;
            rep(u,N) rep(v,N) {
                chmin(D[u][v], D[u][i]+d+D[j][v]);
                chmin(D[u][v], D[u][j]+d+D[i][v]);
                D[v][u] = D[u][v];
            }
        }
    }
    rep(i,N) rep(j,N) if(D[i][j]!=A[i][j]) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}