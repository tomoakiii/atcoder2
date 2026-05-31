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
    ll N,K;
    cin >> N >> K;
    vector C(N, vector<ll>(N));
    rep(i,N) rep(j,N) cin>>C[i][j];
    
    auto dbling = [&N](vector<vector<ll>> &dpin1, vector<vector<ll>> &dpin2)->vector<vector<ll>>{
        vector dpout(N, vector<ll>(N,INF));
        rep(k,N) rep(i,N) rep(j,N) chmin(dpout[i][j], dpin1[i][k]+dpin2[k][j]);
        return dpout;
    };
    vector dp1(N, vector<ll>(N, 0));
    rep(i,N) rep(j,N) {
        dp1[i][j] = C[i][j];
    }
    int cnt = 1;
    vector ans(N, vector<ll>(N,INF));
    rep(i,N) ans[i][i] = 0;
    K--;
    while(K) {
        if(K%2) {
            auto tmp = dbling(ans, dp1);
            swap(tmp, ans);
        }
        auto dp2 = dbling(dp1,dp1);
        swap(dp1,dp2);
        K/=2;
        cnt++;
    }
    rep(i,N) {
        ll mn = INF;
        rep(j,N) {
            chmin(mn, ans[i][j] + C[j][i]);
        }
        cout << mn << endl;
    }
    return 0;
}