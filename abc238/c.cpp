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
typedef modint998244353 mint;
int main(){
    ll N;
    cin >> N;
    auto func = [&](mint st) -> mint {
        return (st) * (st+1) / 2;
    };
    mint k = 1;
    mint ans = 0;
    rep(i,19){
        if(N >= k.val()*10) {
            ans += func(k*10-k);
            if(N==k.val()) break;
        } else {
            ans += func(N-k+1);
            break;
        }
        k *= 10;
    }
    cout << ans.val() << endl;
    return 0;
}