#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);

    ll sm = 0;
    rep(i, N) {
        cin >> A[i];
        sm += A[i];
    }
    ll ans = 0;
    vector<ll> S(N+1);
    rep(i, N) {
        S[i+1] = S[i] ^ A[i];
    }

    ll t = 1;
    rep(k, 30) {
        ll c0=0, c1=0;
        rep (i,N+1) {
            if (S[i]>>k & 1 == 1) {
                c1++;
            } else {
                c0++;
            }
        }
        ans += (c0 * c1) * t;
        t *= 2;
    }
    ans -= sm;
    cout << ans << endl;
    return 0;
}