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
    ll N, M, X;
    cin >> N;
    vector<int> A(N, 0);
    rep(i,N) cin>>A[i];
    cin>>M;
    vector<bool> B(10E5+1, false);
    rep(i,M) {
        int b;
        cin >> b;
        B[b] = true;
    }
    cin >> X;
    vector<bool> dp(X+1);
    dp[0] = true;
    rep(i, X) {
        if(B[i]) continue;
        if (!dp[i]) continue;
        for(int a : A) {
            if(i+a > X) continue;
            dp[i+a] = true;
        }
    }
    if (dp[X]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}