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
    ll N,Q,M;
    cin >> N >> Q >> M;
    vector<ll> D(N),P(N);
    rep(i,N) {
        cin>>D[i]>>P[i];
        P[i]--;
    }
    int K=100;
    vector dp(K+1, vector<ll>(N));
    vector dv(K+1, vector<ll>(N));
    vector<ll> p10(K+1,1);
    p10[1] = 10%M;

    rep(i,N) {
        dp[0][i] = i;
        dp[1][i] = P[i];
        dv[1][i] = D[i];
    }


    for(int k=1; k<K; k++) {
        p10[k+1] = (p10[k] * p10[k])%M;
        rep(i,N) {
            int nx = dp[k][i];
            dp[k+1][i] = dp[k][nx];
            ll nv = dv[k][i];
            nv *= p10[k];
            nv += dv[k][nx];
            nv %= M;
            dv[k+1][i] = nv;
        }
    }
    while(Q--) {
        ll s, k; cin>>s>>k;
        s--;
        int st = s;
        ll ans = 0;
        int i = 1;
        while(k) {
            if(k%2) {
                ans = (p10[i] * ans + dv[i][st]) % M;
                st = dp[i][st];
            }
            k /= 2;
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}