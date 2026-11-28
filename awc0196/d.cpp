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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    vector<ll> dp(K);
    rep(i,N){
        vector<ll> dp2(K);
        vector<pair<ll,int>> v(2, {INF,-1});
        vector<ll> C(K);
        rep(j,K){
            cin>>C[j];
            chmin(v[1], {dp[j], j});
            sort(v.begin(),v.end());
        }
        rep(j,K){
            if(j==v[0].second) dp2[j]=v[1].first+C[j];
            else dp2[j]=v[0].first+C[j];
        }
        swap(dp,dp2);
    }
    ll ans=INF;
    for(auto d:dp)chmin(ans,d);
    cout<<ans<<endl;
    return 0;
}