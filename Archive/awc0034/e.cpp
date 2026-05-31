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
    vector<ll> P(N),W(N-1);
    rep(i,N) cin>>P[i];
    rep(i,N-1) cin>>W[i];
    ll M=1ll<<N;
    vector dp(M, vector<ll>(N));
    set<pair<ll,int>> st;
    rep(i,N) st.insert({1ll<<i,i});
    rep(i,N-1) {
        set<pair<ll,int>> st2;
        for(auto [s,last]:st) {
            rep(j,N) {
                ll ns=s | (1ll<<j);
                if(s==ns) continue;
                chmax(dp[ns][j], dp[s][last] + abs(P[j]-P[last])*W[i]);
                st2.insert({ns, j});
            }
        }
        swap(st,st2);
    }
    ll ans=0;
    rep(i,N) {
        chmax(ans,dp[M-1][i]);
    }
    cout<<ans<<endl;
    return 0;
}