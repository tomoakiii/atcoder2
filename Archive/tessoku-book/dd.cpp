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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    ll N; cin>>N;
    ll d[] = {3,5,7};
    ll ans = 0;
    for(ll k=1; k < (1<<3); k++) {
        ll x = 1;
        int popcount = 0;
        rep(i,3) {
            if(k>>i & 1) {
                x *= d[i];
                popcount++;
            }
        }
        ll p = N/x;
        if(popcount%2) ans += p;
        else ans -= p;
    }
    cout << ans << endl;
    return 0;
}