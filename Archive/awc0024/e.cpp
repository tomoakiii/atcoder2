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
    ll N,W;
    cin >> N >> W;

    unordered_map<ll,ll> mp;
    rep(i,N) {
        ll l, c; cin>>l>>c;
        mp[l]+=c;
    }
    vector<pair<ll,ll>> v;
    for(auto [m,c]:mp) {
        ll s = 1;
        while(c >= s) {
            v.push_back({m*s, s});
            c-=s;
            s*=2;
        }
        if(c>0) v.push_back({m*c, c});
    }
    int M = v.size();
    vector<ll> dp(W+1, INF);
    dp[0] = 0;

    rep(i,M) {
        auto dp_new = dp;
        rep(j,W) {
            ll nw = j + v[i].first;
            if(nw <= W) {
                chmin(dp_new[nw], dp[j] + v[i].second);
            }
        }
        swap(dp,dp_new);
    }
    if(dp[W]==INF) cout<<-1<<endl;
    else cout<<dp[W]<<endl;
    return 0;
}