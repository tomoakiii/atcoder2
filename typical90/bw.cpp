#include <bits/stdc++.h>
#include <atcoder/all>
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
    ll k = N;
    ll i = 2;
    ll p = 0;
    while(true){
        while(k%i == 0) {
            p++;
            k /= i;
        }
        if(i*i > N) break; // break here. for(; i*i<=K ;) is NG
        i++;
    }
    if(k > 1) p++;

    ll ans = 0;
    ll m = 1;
    while(p > m) {
        m *= 2;
        ans++;
    }

    cout << ans << endl;
    return 0;
}