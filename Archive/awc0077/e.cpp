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
    ll N, M;
    cin >> N >> M;
    mf_graph<ll> G(N+M+2);
    rep(i,M) {
        ll b; cin>>b;
        G.add_edge(0, i+1, b);
    }

    rep(i,N){
        int k; cin>>k;
        rep(j,k){
            int c; cin>>c;
            G.add_edge(c, 1+M+i, 1);
        }
        G.add_edge(1+M+i, N+M+1, 1);
    }
    cout<<G.flow(0,1+N+M)<<endl;
    return 0;
}