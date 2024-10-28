#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef __uint128 ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll A, X, M;
    cin >> A >> X >> M;
    if (A==1) {
        cout << X%M << endl;
        return 0;
    }

    const int N = 2E6;    
    ll MOD = M * (A-1);
    vector<ll> Ap(N);
    Ap[0] = A % MOD;
    ll k = 1;
    for(int i=0; i < N; i++) {
        Ap[i+1] = (Ap[i] * Ap[i]) % MOD;
    }
    ll ans = 1;
    int cnt = 0;
    while(X) {
        if (X%2) {
            ans *= (Ap[cnt] % MOD);
        }
        X/=2;
        cnt++;
    }
    ans /= (A-1);
    cout << ans << endl;
    return 0;
}