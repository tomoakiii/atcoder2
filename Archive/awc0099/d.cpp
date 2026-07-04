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
    ll N,L,K;
    cin >> N >> L >> K;
    vector<ll> dp(L+1, -INF);
    dp[0] = 0;
    rep(query,N) {
        ll w,b; cin>>w>>b;
        auto dp2=dp;
        rep(last, L+1){
            if(dp[last] < 0) continue;
            for(int i = 1; i <= K ; i++) {
                ll st = last + i;
                ll ed = st + w - 1;
                if(ed > L) break;
                chmax(dp2[ed], dp[last] + b);
            }
        }
        swap(dp,dp2);
    }
    ll ans = -1;
    for(auto i=L-K+1; i<=L; i++) chmax(ans, dp[i]);
    cout<<ans<<endl;
    return 0;
}