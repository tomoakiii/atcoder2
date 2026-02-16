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
typedef pair<ll,int> pli;
int main(){
    int N, K; cin>>N>>K;
    vector<pair<int,int>> oLR(N), LR(N), RL(N);
    rep(i,N) {
        int L,R; cin>>L>>R;
        RL[i] = {R,L};
        oLR[i] = LR[i] = {L,R};
    }
    sort(RL.begin(),RL.end());
    sort(LR.rbegin(),LR.rend());
    const int M = 86400;

    vector<int> dp(M+1), dpr(M+1);
    int last = -INFi;
    rep(i,N) {
        auto [R,L] = RL[i];
        if (L >= K+last) {
            last = R;
            dp[last]++;
        }
    }
    last = INFi;
    rep(i,N) {
        auto [L,R] = LR[i];
        if (R <= last-K) {
            last = L;
            dpr[last]++;
        }
    }
    rep(i,M) dp[i+1] += dp[i];
    for(int i=M; i>0; i--) dpr[i-1] += dpr[i];

    rep(i,N) {
        ll sm = 1;
        auto [L,R] = oLR[i];
        if(L-K >= 0) sm += dp[L-K];
        if(R+K <= M) sm += dpr[R+K];
        cout << sm << endl;
    }
    return 0;
}