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
    ll N,S,T;
    cin >> N >> S>>T;
    vector dp(N+1, vector<ll>(S+1,-INF));
    dp[0][0] = 0;

    ll ans = INF;
    rep(i,N) {
        ll p,c,w; cin>>p>>c>>w;
        ll b = p-c;
        if(b<0) continue;
        vector dp_new = dp;
        rep(j,N) {
            rep(k,S) {
                if(k+w > S) break;
                chmax(dp_new[j+1][k+w], dp[j][k] + b);
                if(dp_new[j+1][k+w] >= T) chmin(ans, j+1);
            }
        }
        swap(dp,dp_new);
    }
    if(ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}