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
    ll N, M, RK;
    cin >> N >> M >> RK;
    vector<ll> R(RK);
    rep(i,RK) {
        cin>>R[i];
        R[i]--;
    }
    sort(R.begin(), R.end());
    vector D(N, vector<ll>(N,INF));
    rep(i,M) {
        int u,v; ll d;
        cin>>u>>v>>d;
        u--, v--;
        D[u][v] = D[v][u] = d;
    }
    rep(k,N)rep(i,N)rep(j,N) chmin(D[i][j], D[i][k]+D[k][j]);
    ll ans = INF;
    do{
        ll sm = 0;
        rep(i,RK-1) {
            sm += D[R[i+1]][R[i]];
        }
        chmin(ans, sm);
    }while(next_permutation(R.begin(),R.end()));

    cout<<ans<<endl;
    return 0;
}