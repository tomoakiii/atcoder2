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
typedef modint1000000007 mint;
int main(){
    ll N, B, K;
    cin >> N >> B >> K;
    vector<ll> C(K);
    rep(i,K) cin>>C[i];
    vector<mint> dp(B);
    rep(i,N) {
        vector<mint> ndp(B);
        rep(j, B) {
            ndp[][]
        }
    }
    return 0;
}

c * 10^p = B*A + r