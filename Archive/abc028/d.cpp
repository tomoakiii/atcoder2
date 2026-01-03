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
    ll N,K;
    cin >> N >> K;
    ll p = 0;
    p += 1; // 3 times K
    p += 3 * (N-1); // 2 times K
    p += 6 * ((K-1) * (N-K));
    double ans = (double)p / (double)N /(double)N/(double)N;
    printf("%.10f\n", ans);
    return 0;
}