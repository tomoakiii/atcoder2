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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N, 0);
    rep(i,N) cin >> A[i];
    
    int l = 0, r = 0;
    ll v = 0;
    vector<int> Kl(N), Kr(N), Klr(N, -1);
    while(r <= N-1) {
        if (v <= K || l == r) {
            r++;
            if (r >= N) break;
            v += A[r];
        }
        else {            
            v -= A[l];
            l++;
        }
        if (v == K) {
            Kl[l]++;
            Kr[r]++;
            Klr[l] = r;
        }
    }

    vector<mint> p2(N);
    p2[0] = 1;
    rep(i, N-1) p2[i+1] = 2 * p2[i];   

    mint ans = 0;
    int cnt = 0;
    rep(l, N) {
        if (Klr[l] == -1) continue;
        int r = Klr[i];
        if (Kr[r])
        ans = ans + p2[l-1] * p2[N-r-2]

    }
    cout << sm << endl;
    return 0;
}