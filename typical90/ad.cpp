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
    ll N, K;
    cin >> N >> K;
    vector<ll> c(N+1);
    for(ll i=2; i<=N; i++) {
        if(c[i] != 0) continue;
        for(ll k = 1; k*i <= N; k++) {
            c[i*k]++;
        }
    }
    ll ans=0;
    for(ll i=2; i<=N; i++) {
        if(c[i]>=K) ans++;
    }
    cout << ans << endl;
    return 0;
}