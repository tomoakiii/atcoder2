#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, S;
    cin >> N >> S;
    vector A(N, vector<ll>(2));
    vector dp(N+1, vector<bool>(S+1));
    dp[0][0] = 1;

    rep(i, N) cin >> A[i][0] >> A[i][1];
    for(ll i=1; i<=N; i++) {
        rep(j, S+1) {
            if(!dp[i-1][j]) continue;
            rep(k, 2){
                ll sm = j + A[i-1][k];
                dp[i][sm] = true;
            }
        }
    }
    vector<char> ans(N, 'H');
    if (dp[N][S]) {
        ll cur = S;
        cout << "Yes" <<endl;
        for(int i=N; i>0; i--) {
            rep(k, 2){
                if (cur < A[i-1][k]) continue;
                if(!dp[i-1][cur - A[i-1][k]]) continue;
                cur = cur - A[i-1][k];
                ans[i-1] = ((k==0)?'H':'T');
                break;
            
            }
        }
        rep(i, N){
            cout<<ans[i];
        }
        cout<<endl;
    }
    else cout << "No" << endl;
    return 0;
}