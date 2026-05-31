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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> S(N),A(N+1);
    rep(i,N) cin>>S[i];

    rep(i,Q) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        A[u]++;
        A[v+1]--;
    }
    rep(i,N)A[i+1]+=A[i];
    rep(i,N) cout<<max(0ll, S[i]-A[i])<<" \n"[i==N-1];
    return 0;
}