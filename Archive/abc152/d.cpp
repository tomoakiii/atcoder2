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
    ll N; cin >> N;
    vector ce(10, vector<ll>(10));
    for(ll k=1; k<=N; k++) {
        ll kk = k;
        while(kk >= 10) {
            kk /= 10;
        }
        ce[k%10][kk]++;
    }
    ll ans = 0;
    for(ll k=1; k<=N; k++) {
        ll kk = k;
        while(kk >= 10) {
            kk /= 10;
        }        
        ans += ce[kk][k%10];
    }
    cout << ans << endl;
    return 0;
}