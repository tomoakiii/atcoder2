// https://atcoder.jp/contests/abc228/editorial/2932
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

const ll MOD = 998244353;

// a^p = a, a^(p-1) = 1 (mod p)
ll PowMod(ll a, ll p, ll mod) {
    if(!p) return 1;
    a %= mod;
    ll r = PowMod(a, p/2, mod) % mod;
    (r*=r) %= mod;
    if(p%2) (r*=a) %= mod;
    return r;
}


// ans = pow(M, pow(K, N));
// p = K^N = C * (MOD-1) + y
// M^p = M^(C*(MOD-1)) + M^y = M^y
int main(){
    ll N,K,M;
    cin >> N >> K >> M;
    if(M%MOD == 0) {
        cout<<0<<endl;
        return 0;
    }
    ll y = PowMod(K,N,MOD-1);
    ll x = PowMod(M,y,MOD);    
    cout << x << endl;
    return 0;
}