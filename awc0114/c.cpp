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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, M;
    cin >> N >> M;
    set<pair<ll,ll>> XC;
    rep(i,N) {
        ll x,c; cin>>x>>c;
        XC.insert({x,c});
    }
    ll ans=0;
    rep(i,M){
        ll l,r; cin>>l>>r;
        auto it = XC.lower_bound({l,0});
        while(it != XC.end() &&  it->first <= r) {
            ans += it->second;
            it = XC.erase(it);
        }
    }
    cout<<ans<<endl;
    return 0;
}