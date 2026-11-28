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
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> CV(N);
    rep(i,N) cin>>CV[i].first>>CV[i].second;
    sort(CV.rbegin(), CV.rend());
    ll bs = 0;

    rep(j,M+1){
        vector<ll> dp(M+1);
        rep(i,CV.size()){
            auto dp2 = dp;
            rep(j2,M){
                ll nj = j2+CV[i].first;
                if(nj > M) break;
                chmax(dp2[nj], dp[j2]+CV[i].second);
            }
            swap(dp,dp2);
        }
        ll ans = 0;
        rep(j2,M+1)chmax(ans, dp[j2]);
        cout<<ans+bs<<endl;
        for(int i=CV.size()-1; i>=0; i--){
            CV[i].first--;
            if(CV[i].first == 0){
                bs += CV[i].second;
                CV.pop_back();
            }
        }
    }
    return 0;
}