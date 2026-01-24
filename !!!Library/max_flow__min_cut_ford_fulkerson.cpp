//https://atcoder.jp/contests/abc010/submissions/me

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
    ll N,G,E; cin>>N>>G>>E;
    vector<int> P(G);
    rep(i,G) {
        cin>>P[i];
    }
    mf_graph<ll> GF(N+1);
    rep(i,E) {
        int u,v;
        cin>>u>>v;
        GF.add_edge(u,v,1);
        GF.add_edge(v,u,1);
    }
    rep(i,G) {
        GF.add_edge(P[i],N,1);
    }
    cout << GF.flow(0,N) << endl;

    return 0;
}