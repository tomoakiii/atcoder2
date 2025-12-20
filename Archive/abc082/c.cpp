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
    const ll M = 2e5;
    map<ll,ll> P;
    ll N; cin>>N;
    rep(i,N) {
        ll a; cin>>a;
        P[a]++;
    }
    ll ans = 0;
    for(auto [v,c]:P) {
        if(c < v) ans += c;
        else ans += c-v;
    }
    cout<<ans<<endl;
    return 0;
}