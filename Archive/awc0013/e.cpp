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
    ll N,M; cin>>N>>M;
    mf_graph<int> GF(N+M+2);
    rep(i,N) {
        ll K; cin>>K;
        rep(j,K) {
            int c; cin>>c; c--;
            GF.add_edge(c, i+M, 1);
            //cerr<<c<<"-"<<i+M<<endl;
        }
    }
    rep(i,M) {
        GF.add_edge(N+M, i, 1);
        //cerr<<N+M<<"-"<<i<<endl;
    }
    rep(i,N) {
        GF.add_edge(M+i, N+M+1, 1);
        //cerr<<M+i<<"-"<<N+M+1<<endl;
    }
    cout << GF.flow(N+M,M+N+1) << endl;
    return 0;
}