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
typedef pair<ll,ll> pll;

pll lcm_d(pll x, pll y){
    return {lcm(x.first, y.first), gcd(x.second, y.second)};
}

int main(){
    int N;
    cin >> N;
    vector<pll> PQ(N);
    pll ans = {1,0};
    // cin>>ans.first>>ans.second;
    rep(i,N) {
        pll a; cin>>a.first>>a.second;
        ans = lcm_d(ans, a);
    }
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}