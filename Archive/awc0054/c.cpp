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
    ll N,M;
    cin >> N >> M;
    vector<ll> S(N);
    rep(i,N) cin>>S[i];
    vector<ll> A(N+1);
    rep(i,M) {
        ll l,r,w; cin>>l>>r>>w;
        l--,r--;
        A[l]+=w;
        A[r+1]-=w;
    }
    rep(i,N) A[i+1]+=A[i];
    ll ans=0;
    rep(i,N) if(A[i]>S[i]) ans++;
    cout<<ans<<endl;
    return 0;
}