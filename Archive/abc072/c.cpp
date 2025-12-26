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
    ll N;
    cin >> N;
    unordered_map<ll,ll> mp;
    ll ans = 0;
    rep(i,N) {
        ll a; cin>>a;
        mp[a-1]++;
        mp[a]++;
        mp[a+1]++;
    }
    for(auto [v,c]:mp) {
        chmax(ans, c);
    }
    cout<<ans<<endl;
    return 0;
}