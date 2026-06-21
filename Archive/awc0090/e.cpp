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
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    S = S + S;
    ll N2 = S.size();
    vector dp(N2+1, vector<int>(N2+1, 0));
    for(int i=N2-1; i>=0; i--){
        for(int j=N2-1; j>=0; j--){
            if(S[i]==S[j]) dp[i][j] = dp[i+1][j+1]+1;
        }
    }
    ll st = 0;
    rep(i,Q) {
        ll a,len;
        cin >> a >> len;
        st += a;
        st %= N;
        ll ans = 0;
        rep(j,N){
            if(dp[st][j] >= len) continue;
            ll p = dp[st][j];
            if(S[st+p] > S[j+p]) {
                ans += len-p;
            }
        }
        cout << ans << endl;
    }
    return 0;
}