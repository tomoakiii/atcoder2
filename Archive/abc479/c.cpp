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
    ll N,W;
    cin >> N >> W;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];
    ll ful=1ll<<N;
    ll ans=0;
    rep(S,ful){
        ll sm = 0, vol=0;
        rep(i,N){
            if(S >> i & 1) {
                vol+=B[i];
                sm+=A[i];
            }
        }
        if(vol>W)continue;
        chmax(ans,sm);
    }
    cout<<ans<<endl;
    return 0;
}