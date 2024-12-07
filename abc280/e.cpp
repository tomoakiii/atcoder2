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
    vector<mint> E(N+1);
    E[N] = 0;
    E[N-1] = 1;
    mint p = P;
    p /= 100;
    mint q = 1-p;
    for(ll i=N-2; i>=0; i--) {
        E[i] = 1 + p * E[i+2] + q * E[i+1];        
    }    
    cout << E[0].val() << endl;
    return 0;
}