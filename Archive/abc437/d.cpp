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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    sort(A.begin(), A.end());
    vector<ll> Asm(N+1);
    rep(i,N) {
        Asm[i+1] = Asm[i] + A[i];
    }

    mint ans = 0;
    rep(i,M) {
        ll b = B[i];
        auto j = lower_bound(A.begin(), A.end(), b) - A.begin();
        ans += Asm[N] - Asm[j];
        ans -= Asm[j];
        ans += j*b;
        ans -= (N-j)*b;
    }
    cout<<ans.val()<<endl;
    return 0;
}