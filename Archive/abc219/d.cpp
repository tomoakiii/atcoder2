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
    ll N,X,Y;
    cin >> N >> X >> Y;
    vector dp(X+1, vector<ll>(Y+1,INF));
    dp[0][0] = 0;
    rep(i,N) {
        ll A,B;
        cin>>A>>B;
        vector dp_new = dp;
        rep(a, X+1) rep(b, Y+1) {
            ll na = min(a+A,X), nb = min(b+B,Y);            
            chmin(dp_new[na][nb], dp[a][b]+1);
        }
        swap(dp,dp_new);
    }
    if(dp[X][Y]<INF) cout<<dp[X][Y]<<endl;
    else cout<<-1<<endl;
    return 0;
}