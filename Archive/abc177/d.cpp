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
    ll N,M;
    cin >> N >> M;
    dsu UF(N);
    rep(i,M) {
        int a,b; cin>>a>>b; a--, b--;
        if(!UF.same(a,b)) UF.merge(a,b);
    }
    int ans = 0;
    for(auto u: UF.groups()) {
        chmax(ans, (int)u.size());
    }
    cout << ans << endl;
    return 0;
}