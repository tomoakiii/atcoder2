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
    ll N,M,T;
    cin >> N >> M >> T;
    vector<pair<ll,ll>> AC(N);
    ll ans = 0;
    rep(i,N) {
        ll a,b,c; cin>>a>>b>>c;
        if(b >= T) ans+= a;
        else {
            AC.push_back({a,c});
        }
    }
    ll sz = AC.size();
    vector<ll> dp(M+1,-INF);
    dp[0]=0;
    rep(i,sz) {
        auto [a,c]= AC[i];
        auto dp_new = dp;
        rep(j,M+1) {
            if(c + j > M) break;
            chmax(dp_new[c+j], dp[j]+a);
        }
        swap(dp, dp_new);
    }
    ll mx = 0;
    rep(j,M+1) {
        chmax(mx, dp[j]);
    }
    cout<<ans+mx<<endl;

    return 0;
}