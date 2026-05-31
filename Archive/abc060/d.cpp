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
    ll N,Wlim;
    cin >> N >> Wlim;
    vector<ll> W(N), V(N);
    rep(i,N) cin>>W[i]>>V[i];
    ll W0 = W[0]-1;
    rep(i,N) W[i] -= W0;
    vector dp(N+1, vector<ll>(5*N,-INF));
    dp[0][0] = 0;
    ll lW = 5*N;
    rep(i,N) {
        auto dp_new = dp;
        rep(j, N) {
            rep(w, lW-1) {
                if(w + W[i] >= lW) continue;
                chmax(dp_new[j+1][w + W[i]], dp[j][w] + V[i]);
            }
        }
        swap(dp, dp_new);
    }
    ll ans = 0;
    rep(j,N+1) {
        rep(w, lW) {
            if(j*W0 + w > Wlim) break;
            chmax(ans, dp[j][w]);
        }
    }
    cout<<ans<<endl;

    return 0;
}