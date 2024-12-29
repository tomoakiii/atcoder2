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
    int K;
    string S,T;
    cin >> K >> S >> T;
    int sz = (int)S.size(), tz = (int)T.size();
    if(sz > tz) {
        swap(S, T);
        swap(sz, tz);
    }
    int df = tz - sz;
    if(df > K) {
        cout << "No" << endl;
        return 0;
    }

    vector dp(sz + 1, vector<ll>(2*K+4, INF));
    dp[0][K+1] = 0;
    for(int jp = 0; jp <= K+1; jp++){
        int nj = jp + K + 1;
        dp[0][nj+1] = dp[0][nj]+1;
    }
    for(int i=0; i<sz; i++) {
        for(int jp = -K; jp <= K+1; jp++) {
            int j = i + jp;
            int nj = jp + K;
            int lj = jp + K + 1;
            if(j < 0 || j >= tz) continue;
            if(S[i] == T[j]) {
                chmin(dp[i+1][nj+1], dp[i][lj]);
            } 
            chmin(dp[i+1][nj], dp[i][lj] + 1);
            chmin(dp[i+1][nj+1], dp[i+1][nj] + 1);
            chmin(dp[i+1][nj+1], dp[i][lj] + 1);
        }
    }
    if(dp[sz][df+K+1] <= K) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}