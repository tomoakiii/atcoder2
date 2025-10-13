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
    ll N,T;
    cin >> N >> T;
    vector<pair<ll,ll>> AB(N);
    ll ans = 0;
    rep(i,N) cin>>AB[i].first>>AB[i].second;
    sort(AB.begin(), AB.end());
    rep(last, N) {
        vector<ll> dp(T+1);
        rep(i,N) {
            if(i==last) continue;
            vector<ll> dp_new(T+1);
            rep(j,T) {
                if(j+AB[i].first>T)break;
                chmax(dp_new[j+AB[i].first], dp[j]+AB[i].second); 
            }
            swap(dp, dp_new);
        }
        chmax(ans, dp[T-1]+AB[last].second);
    }
    cout<<ans<<endl;
    return 0;
}