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
    vector dp(8, vector<ll>(2));
    dp[0][0] = 1;
    vector<ll> D;
    while(N){
        D.push_back(N%10);
        N/=10;
    }
    reverse(D.begin(),D.end());

    int sgs[] = {3,5,7};
    bool flg = false;
    for(auto d: D) {
        vector dp_new(8, vector<ll>(2));
        rep(p, 3) {
            if(flg) dp_new[1ll<<p][1] += 1;
            rep(i, 8){
                if(d == sgs[p]) {
                    dp_new[i | 1ll<<p][1] += dp[i][1];
                    dp_new[i | 1ll<<p][0] += dp[i][0];
                } else if(d < sgs[p]) {
                    dp_new[i | 1ll<<p][1] += dp[i][1];
                } else {
                    dp_new[i | 1ll<<p][1] += dp[i][0] + dp[i][1];
                }
            }
        }
        swap(dp, dp_new);
        flg = true;
    }
    cout<<dp[7][1]+dp[7][0]<<endl;
    return 0;
}