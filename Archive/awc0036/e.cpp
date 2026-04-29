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
    ll H,W;
    cin >> H >> W;
    vector A(H,vector<ll>(W));
    rep(i,H) rep(j,W) cin>>A[i][j];
    ll full = 1ll<<H;
    ll ans=0;
    rep(S,full) {
        ll sm=0;
        auto G=A;
        vector<ll> col(W);
        rep(i,H)rep(j,W) {
            if(S>>i & 1) {
                sm+=A[i][j];
            } else {
                col[j]+=A[i][j];
            }
        }
        rep(i,W) if(col[i]>0) sm+=col[i];
        chmax(ans,sm);
    }
    cout<<ans<<endl;
    return 0;
}