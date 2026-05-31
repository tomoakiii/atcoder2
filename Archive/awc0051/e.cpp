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
    fenwick_tree<ll> FT(N);
    vector<ll> G(M);
    rep(i,M) {
        cin>>G[i];
        G[i]--;
        FT.add(G[i],1);
    }
    ll ans=0;
    rep(i,M) {
        FT.add(G[i],-1);
        ans+=FT.sum(0,G[i]);
    }
    cout<<ans<<endl;
    return 0;
}