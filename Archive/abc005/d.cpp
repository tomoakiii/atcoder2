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
    ll N;
    cin >> N;
    vector D(N+1, vector<ll>(N+1));
    rep(i,N)rep(j,N) cin>>D[i+1][j+1];
    rep(i,N)rep(j,N) D[i+1][j+1] += D[i+1][j];
    rep(i,N)rep(j,N) D[i+1][j+1] += D[i][j+1];
    rep(i,N+1){
        rep(j,N+1) cerr<<D[i][j]<<" ";
        cerr<<endl;
    }
    vector<ll> ans(N*N+1);
    for(ll y=1; y<=N; y++) for(ll x=1; x<=N; x++){
        for(ll i=0; i<y; i++) for(ll j=0; j<x; j++) {
            ll yl = y-i, xl = x-j;
            ll p = D[y][x] + D[i][j] - D[i][x] - D[y][j];
            chmax(ans[xl*yl], p);
        }
    }

    rep(i,N*N) {
        chmax(ans[i+1], ans[i]);
    }
    ll Q; cin>>Q;
    while(Q--) {
        ll p; cin>>p;
        cout << ans[p] << endl;
    }

    return 0;
}