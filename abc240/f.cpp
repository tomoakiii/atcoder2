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

void solve(){
    ll N,M; cin>>N>>M;
    vector<ll> X(N),Y(N);
    rep(i,N) cin>>X[i]>>Y[i];
    ll ans = X[0];
    ll Blast = 0;
    rep(i,N) {
        if(X[i] < 0) {
            Blast += Y[i]*X[i];
        }
        Blast += X[i]*Y[i]*(Y[i]+1)/2;
        chmax(ans, Blast);
    }
    cout<<ans<<endl;
}


int main(){
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}