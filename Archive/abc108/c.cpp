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
    ll N,K;
    cin >> N >> K;
    vector<ll> M(K);
    for(ll n=1; n<=N; n++) {
        M[n%K]++;
    }
    ll ans = 0;
    rep(i,K) {
        if((K-i)%K != i) continue;
        if(M[i]>=3) ans += M[i] * (M[i]-1) * (M[i]-2);  // 3種類
        if(M[i]>=2) ans += 6 * M[i] * (M[i]-1) / 2; // 2種類
        ans += M[i]; // 1種類

    }
    cout << ans << endl;
    return 0;
}