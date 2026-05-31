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
    vector<pair<ll,ll>> WvH{};
    ll happy = 0, weight = 0;
    rep(i,N) {
        ll w,h,b; cin>>w>>h>>b;
        weight += w;
        happy += b;
        if(h > b) {
            WvH.push_back({h-b, 2*w});
        }
    }
    vector<ll> dp(weight + 1, -INF);
    dp[0] = 0;
    for(auto [h, w]: WvH) {
        vector new_dp = dp;
        rep(i, weight) {
            if(i+w <= weight) chmax(new_dp[i+w], dp[i] + h);
        }
        swap(dp, new_dp);
    }
    ll mx = 0;
    rep(i, weight+1) chmax(mx, dp[i]);
    cout << happy + mx << endl;
    return 0;
}