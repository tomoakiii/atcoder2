#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x5F5F5F5F;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) {
        cin>>A[i];
        A[i]--;
    }
    const int m = 20;
    const ll M = 1<<m;
    vector<vector<int>> num(m);
    rep(i, N) num[A[i]].push_back(i);

    vector<int> dp(M, INFi);
    int ans = 0;
    dp[0] = 0;
    rep(s, M) {
        rep(nx, m) {
            if (((s>>nx) & 1) > 0) continue;
            ll s2 = s | 1<<nx;
            auto& p = num[nx];
            auto it = lower_bound(p.begin(), p.end(), dp[s]);
            if(it == p.end()) continue;
            it++;
            if(it == p.end()) continue;
            chmin(dp[s2], 1 + (int)(*it));
        }
    }
    for(unsigned int s = 0; s < M; s++) {
        if(dp[s] < INFi) chmax(ans, popcount(s));
    }
    cout << 2*ans << endl;
    return 0;
}