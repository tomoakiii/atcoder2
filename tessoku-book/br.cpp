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


int main() {
    int N,M;
    cin>>N>>M;
    vector<ll> dp(1ll<<N, INF);
    ll p = 0;
    rep(i,N) {
        int a; cin>>a;
        if(a == 1) p |= 1ll<<i;
    }
    dp[p] = 0;
    vector XYZ(M, vector<int>(3));
    rep(i,M) rep(k,3){
        cin>>XYZ[i][k];
        XYZ[i][k]--;
    }
    queue<ll> que;
    que.push(p);
    while(!que.empty()) {
        auto p = que.front();
        que.pop();
        for(auto xyz: XYZ) {
            ll q = p;
            for(auto x: xyz) {
                q ^= (1ll<<x);
            }
            if(dp[q] <= dp[p] + 1) continue;
            dp[q] = dp[p] + 1;
            que.push(q);
        }
    }
    if(dp[(1ll<<N)-1] == INF) cout << -1 << endl;
    else cout << dp[(1ll<<N)-1] << endl;

}