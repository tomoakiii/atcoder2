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
    cin >> H>>W;
    vector C(10,vector<ll>(10));
    vector A(H,vector<ll>(W));
    rep(i,10) rep(j,10) cin>>C[i][j];
    ll ans = 0;
    vector D = C;

    rep(k,10) rep(i,10) rep(j,10) {
        chmin(D[i][j], D[i][k] + D[k][j]);
    }
    rep(i,H) rep(j,W) {
        ll a; cin>>a;
        if(a==-1) continue;
        ans += D[a][1];
    }
    cout<<ans<<endl;

    return 0;
}