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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> B(N+1);
    rep(i,N) B[i+1]=B[i]+A[i];

    vector<ll> C(N), D(N+1);
    rep(i,N) C[i]=max(A[i],0ll);
    rep(i,N) D[i+1]=D[i]+C[i];

    ll ans=-INF;
    for(int r=K; r<=N; r++) {
        int l=r-K;
        ll sm=0;
        sm+=D[l]-D[0];
        sm+=D[N]-D[r];
        sm+=B[r]-B[l];
        chmax(ans,sm);
    }
    cout<<ans<<endl;
    return 0;
}