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

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> A(N);
    vector R(20, vector<ll>{});
    rep(i,N) {
        cin>>A[i];
        ll x = A[i];
        rep(k, 20) {
            x%=M;
            R[k].push_back(x);
            x*=10;
        }
    }
    rep(k, 20) sort(R[k].begin(), R[k].end());
    ll ans = 0;
    rep(i,N) {
        ll g = 0;
        ll t = A[i]%M;
        t = (M-t)%M;
        ll a = A[i];
        while(a > 0) {
            a /= 10;
            g++;
        }
        ans += upper_bound(R[g].begin(), R[g].end(), t) - lower_bound(R[g].begin(), R[g].end(), t);
    }
    cout<<ans<<endl;
    return 0;
}