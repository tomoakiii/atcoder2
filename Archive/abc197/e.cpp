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
typedef pair<ll,ll> pll;
int main(){
    ll N; cin>>N;
    vector CX(N, vector<ll>(2));
    rep(i,N) {
        CX[i][0] = INF;
        CX[i][1] = -INF;
    }
    rep(i,N) {
        ll x,c; cin>>x>>c; c--;
        chmin(CX[c][0], x);
        chmax(CX[c][1], x);
    }
    vector<pll> L{};
    rep(i,N) {
        if(CX[i][0] == INF) continue;
        L.push_back({CX[i][0], CX[i][1]});
    }
    L.push_back({0,0});
    int S = L.size();
    vector dp(S+1, vector<pll>(2, {INF, INF}));
    dp[0][0] = dp[0][1] = {0,0};
    auto calc = [&](pll x, ll y)->pll{
        return {x.first+abs(x.second - y), y};
    };

    rep(i,S) {
        rep(j,2) {
            pll t1 = calc(dp[i][j], L[i].first); 
            t1 = calc(t1, L[i].second);
            chmin(dp[i+1][0], t1);

            pll t2 = calc(dp[i][j], L[i].second); 
            t2 = calc(t2, L[i].first);
            chmin(dp[i+1][1], t2);
        }
    }
    cout<<min(dp[S][0].first,dp[S][1].first)<<endl;
    return 0;
}