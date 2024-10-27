#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    ll ans = INF;
    for(ll k = 1; (k-1)*(k-1) <= M && k<=N; k++) {
        ll p = M/k;
        ll r = M%k;
        ll X = INF;
        if (r>0) {
            if (p+1 <= N){
                X = (p+1)*k;
            }            
        } else {
            if (p <= N) {
                X = M;
            }
        }
        ans = min(ans, X);
    }
    if (ans == INF) cout << -1 << endl;
    else  cout << ans << endl;
    return 0;
}