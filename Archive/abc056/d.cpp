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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
    }
    vector dp(N+1, vector<ll>(K+1));
    dp[0][0] = 1;
    rep(i,N) {
        rep(k,K) {
            dp[i+1][k] += dp[i][k];
            ll nk = k+A[i];
            if(nk > K) continue;
            dp[i+1][nk] += dp[i][k];
            if(dp[i+1][nk] > 2) dp[i+1][nk] = 2;
        }
    }
    vector root(K+1, vector<int>{});
    rep(i,K+1) {
        int st = i;
        if(dp[N][st] == 1) {
            for(int j=N-1; j>=0; j--) {
                if(st-A[j] < 0) continue;
                if(dp[N][st-A[j]] == 1){
                    root[i].push_back(j);
                    st = st-A[j];
                }
            }
            sort(root[i].begin(), root[i].end());
        }
    }
    ll ans = 0;
    rep(i,N) {
        ll sx = K-A[i];
        if(sx < 0) sx = 0;
        bool flg = true;
        for(int x=sx; x<K; x++) {
            if(dp[N][x] >= 2) {
                chmax(flg, 0);
            }
            if(dp[N][x] == 1) {
                auto it = lower_bound(root[x].begin(), root[x].end(), i);
                if(*it != i) {
                    flg = false;
                }
            }
        }
        if(flg <= 0) continue;

    }
    cout<<ans<<endl;
    return 0;
}