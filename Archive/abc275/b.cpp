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
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    mint ans = a, ans2 = d;
    ans = ans * b;
    ans = ans * c;
    ans2 = ans2 * e;
    ans2 = ans2 * f;
    ans = ans - ans2;
    cout << ans.val() << endl;
    return 0;
}