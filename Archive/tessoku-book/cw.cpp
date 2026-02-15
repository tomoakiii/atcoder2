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
    ll N; cin>>N;
    vector<pair<ll,ll>> XY(N);
    rep(i,N) {
        cin>>XY[i].first>>XY[i].second;
        XY[i].second *= -1;
    }
    sort(XY.begin(), XY.end());
    vector<ll> dp(N+1,INF);
    int ans = 0;
    rep(i,N) {
        ll Y = -XY[i].second;
        int it = lower_bound(dp.begin(), dp.end(), Y) - dp.begin();
        dp[it] = Y;
        chmax(ans, it+1);
    }
//    rep(i,N+1) cerr<<dp[i]<<endl;
    cout << ans << endl;
    return 0;
}