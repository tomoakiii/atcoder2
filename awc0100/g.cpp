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
    ll N,M;
    cin >> N >> M;
    dsu UF(N+1);
    rep(i,M){
        int u,v;cin>>u>>v;
        UF.merge(u,v);
    }
    vector<ll> size(N+1);
    rep(i,N+1){
        size[UF.leader(i)]++;
    }
    int Q; cin>>Q;
    while(Q--){
        int s; cin>>s;
        cout<<size[UF.leader(s)]<<endl;
    }

    return 0;
}