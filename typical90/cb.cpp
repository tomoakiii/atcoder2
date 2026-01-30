#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,D; cin>>N>>D;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> S(1ll<<N);
    vector<bool> visit(((ll)1)<<N);
    vector<ll> pow2D(D+1,1);
    rep(i,D) pow2D[i+1] = pow2D[i]*2;
    ll ans = 0;
    rep(k, ((ll)1)<<N) {
        rep(i,N) {
            ll k2 = k | ((ll)1)<<i;
            S[k2] = S[k] | A[i];
            if(visit[k2]) continue;
            visit[k2] = true;
            auto p = popcount(S[k2]);
            ll v = pow2D[D] - pow2D[D-p];
            auto q = popcount(k2);
            if(q%2==1) ans += v;
            else ans -= v;
        }
    }
    cout << ans << endl;
    return 0;
}