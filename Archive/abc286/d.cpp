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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), B(N);
    rep(i,N) cin>>A[i]>>B[i];
    vector<bool> dp(X+1);
    dp[0] = true;
    rep(i,N) {
        set<ll> st;
        rep(k, X){
            if (!dp[k]) continue;
            st.insert(k);
        }
        for (auto k: st) {
            rep(j, B[i]){
                ll nx = k+(j+1)*A[i];
                if (nx > X) break;
                dp[nx] = true;
            }
        }
    }
    if (dp[X]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}