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
typedef modint1000000007 mint;
int main(){
    ll N, K;
    cin >> N >> K;
    mint ans = 1;
    if(N==1) {
        ans *= K;
        cout << ans.val() << endl;
        return 0;
    } else if (N==2) {
        ans *= K;
        ans *= K-1;
        cout << ans.val() << endl;
        return 0;
    }
    N-=2;
    mint p = K-2;
    ans *= K;
    ans *= K-1;
    while(N) {
        if(N%2 > 0) ans *= p;
        p *= p;
        N/=2;
    }
    cout << ans.val() << endl;
    return 0;
}