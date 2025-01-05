#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef long long ll;

typedef long long ll;
int main(){
    int N, K;
    cin >> N >> K;
    const int M = 5000;
    vector S(M+1, vector<int>(5001));
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        S[a][b]++;
        int ak = min(a+K+1, M);
        int bk = min(b+K+1, M);    
        S[ak][b]--;
        S[a][bk]--;
        S[ak][bk]++;
    }
    rep(i, M) {
        rep (j, M) {
            S[i][j+1] += S[i][j];
        }
    }
    rep(j, M) {
        rep (i, M) {
            S[i+1][j] += S[i][j];
        }
    }
    int ans = 0;
    rep(i,M) rep(j,M) chmax(ans, S[i][j]);
    cout << ans << endl;
    return 0;
}