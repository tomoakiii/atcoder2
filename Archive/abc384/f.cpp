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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    int m = 25;
    vector<ll> d(m);
    rep(k, m){
        ll mod = 1<<k;
        vector<ll> sum(mod), cnt(mod);
        rep(i,N) {
            ll p = (mod - A[i]%mod)%mod;
            ll am = A[i] % mod;
            sum[am]+=A[i];
            cnt[am]++;
            d[k] += cnt[p] * A[i] + sum[p];
        }
    }
    rep(k, m-1) {
        d[k] -= d[k+1];
    }
    ll ans = 0;
    rep(k, m) {
        d[k] >>= k;
        ans += d[k];
    }
    cout << ans << endl;


    return 0;
}