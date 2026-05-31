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
    ll N,K;
    cin >> N >> K;
    unordered_map<ll, ll> mp;
    rep(i,N) {
        ll a; cin>>a;
        mp[a]++;
    }
    set<pair<ll, ll>> st;
    for(auto [v,c]: mp) {
        st.insert({c,v});
    }
    ll ans = 0;
    while(st.size() > K) {
        ans += st.begin()->first;
        st.erase(st.begin());
    }
    cout<<ans<<endl;
    return 0;
}