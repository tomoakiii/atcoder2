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

typedef modint998244353 mint;

int main(){
    ll N, P;
    cin >> N >> P;
    mint hit1 = P;
    hit1 = hit1 / 100;
    mint hit2 = 1 - P;
    mint ans = 0;
    vector<mint> P1N(N+1), PN1(N+1);
    P1N[1] = 1;
    PN1[N] = N;
    for(ll i=2; i<=N; i++) {
        P1N[i] = P1N[i-1] * i;
    }
    for(ll i=N-1; i>=1; i--) {
        PN1[i] = PN1[i+1] * i;
    }
    mint p1 = 1, p2 = 1;
    rep(i,N) p2 *= hit2;
    

    for(ll i=0: i<=N; i++) {

    }
    cout << dp[N].val() << endl;
    return 0;
}