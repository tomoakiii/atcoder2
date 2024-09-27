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

// ai + bj = g
ll extgcd(ll a, ll b, ll &i, ll &j){
    if (b == 0) {i = 1; j = 0; return a;}
    ll p = a/b;
    ll g = extgcd(b, a-b*p, j, i);
    j -= p*i;
    return g;
}


int main(){
    ll X = 27, Y = 36;
    ll A, B;
    ll g = extgcd(X, Y, B, A);

    cout << "A=" << A << endl;
    cout << "B=" << B << endl;
    cout << "GCD=" << g << endl;
    return 0;
}