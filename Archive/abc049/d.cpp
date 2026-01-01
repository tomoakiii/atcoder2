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
    ll N, K, L;
    cin >> N >> K >> L;
    dsu Road(N), Rail(N), Both(N);
    rep(i,K) {
        int u,v; cin>>u>>v; u--, v--;
        Road.merge(u,v);
    }
    rep(i,L) {
        int u,v; cin>>u>>v; u--, v--;
        Rail.merge(u,v);
    }
    map<pair<int,int>, int> mp;
    rep(i,N) mp[{Road.leader(i), Rail.leader(i)}]++;
    rep(i,N) cout<<mp[{Road.leader(i), Rail.leader(i)}]<<endl;
    return 0;
}