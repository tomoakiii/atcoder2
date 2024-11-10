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
    vector<mint> h1p(N+1), h2p(N+1); 
    h1p[0] = hit1, h2p[0] = hit2;
    for(ll i=1; i<=N; i++) {
        h1p[i] = h1p[i-1] * hit1;
        h2p[i] = h2p[i-1] * hit2;
    }

    vector<mint> xK(N+1), xKinv(N+1);
    xK[0] = 1;
    xKinv[N] = N;
    for(ll x=0; x<N; x++){
        xK[x+1] = xK[x] * (x+1);
    }
    for(ll i=N-1; i>0; i--) {
        xKinv[i] = xKinv[i+1] * i;
    }
    xKinv[0] = 1;
    mint invN = 1/xK[N];
    auto inv = [&](ll x)->mint{
        return (xKinv[x] * invN);
    };
    auto nCr = [&](ll n, ll r)->mint{
        return (xK[n] * inv(r) * inv(n-r));
    };

    mint ans = 0;
    for(ll i=0; i<=(N+1)/2; i++) {
        mint C = nCr(N-i, 2*i);
        ans += (N-i) * C * h2p[i] * h1p[N-2*i-1];
    }
    cout << ans.val() << endl;
    return 0;
}