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
    vector<ll> A(N+1);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        A[u]++;
        A[v+1]--;
    }
    rep(i,N)A[i+1]+=A[i];
    ll ans=0;
    rep(i,N)ans+=A[i]%2;
    cout<<ans<<endl;
    return 0;
}