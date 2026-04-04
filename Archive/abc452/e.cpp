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
    mint ans=0;
    mint iai = 0;
    rep(i,N) {
        cin>>A[i];
        iai += (i+1) * A[i];
    }
    mint bsm = 0;
    rep(i,M) {
        cin>>B[i];
        bsm += B[i];
    }
    vector<ll> AS(N+1);
    rep(i,N) AS[i+1] = A[i] + AS[i];
    ans += bsm * iai;
    rep(j,M) {
        ll j1 = j+1;
        mint p = 0;
        for(int i=j1; i<=N; i+=j1) {
            mint sm = AS[N] - AS[i-1];
            ans -= j1*B[j]*sm;
        }
    }
    cout<<ans.val()<<endl;
    return 0;
}