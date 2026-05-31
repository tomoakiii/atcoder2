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
    ll N,D;
    cin >> N >> D;
    vector<ll> dp(D+1,INF);
    dp[D]=0;
    vector<ll> C(N),F(N);
    rep(i,N) {
        cin>>C[i]>>F[i];
    }
    for(ll d=D; d>=0; d--){
        rep(i,N){
            chmin(dp[max(d-F[i], 0ll)], dp[d]+C[i]);
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}