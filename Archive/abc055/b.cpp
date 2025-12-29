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
<<<<<<< HEAD:abc054/c.cpp
    ll A,B,C,D; cin>>A>>B>>C>>D;
    ll ans = 0;
    chmax(ans, A*B);
    chmax(ans, C*D);
    cout<<ans<<endl;
=======
    ll N;
    cin >> N;
    mint ans = 1;
    for(ll i=1; i<=N; i++) ans *= i;
    cout << ans.val() << endl;
>>>>>>> refs/remotes/origin/main:Archive/abc055/b.cpp
    return 0;
}