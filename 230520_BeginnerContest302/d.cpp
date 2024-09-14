#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ia = N-1, ib = M-1;
    ll ans = -1;
    while(ib >= 0) {
        while(ia > 0 && A[ia] - B[ib] > D){
            ia--;
        }
        if (abs(A[ia] - B[ib]) <= D) ans = max(ans, A[ia]+B[ib]);
        ib--;
    }
    ia = N-1, ib = M-1;
    while(ia >= 0) {
        while(ib > 0 && B[ib] - A[ia] > D){
            ib--;
        }
        if (abs(A[ia] - B[ib]) <= D) ans = max(ans, A[ia]+B[ib]);
        ia--;
    }

    cout << ans << endl;
    return 0;
}