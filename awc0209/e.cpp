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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    scc_graph G(N);

    vector<ll> P(N),A(N);
    rep(i,N) {
        cin>>P[i];
        P[i]--;
    }
    rep(i,N) cin>>A[i];
    rep(i,N){
        G.add_edge(i,P[i]);
    }
    vector<ll> score(N);
    for(auto gv:G.scc()){
        if(gv.size() == 1){
            score[P[gv[0]]] += score[gv[0]] + A[gv[0]];
        }
    }

    return 0;
}