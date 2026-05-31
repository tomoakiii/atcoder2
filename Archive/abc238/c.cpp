#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef modint998244353 mint;
int main(){
    ll N;
    cin >> N;
    mint d2 = 1;
    d2 /= 2;
    auto func = [&](mint st) -> mint {
        return (st) * (st+1) * d2;
    };
    ll k = 1;
    mint ans = 0;
    while(N) {        
        if(N/10 >= k) {
            ans += func(9*k);
        } else {
            ans += func(N-k+1);
            break;
        }
        k *= 10;
    }
    cout << ans.val() << endl;
    return 0;
}