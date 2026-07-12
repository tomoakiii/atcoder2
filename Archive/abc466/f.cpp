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

void solve(){
    ll N, X; cin>>N>>X;
    vector<ll> A;
    ll last= INF;
    rep(i,N){
        ll a; cin>>a;
        if(a<last) {
            A.push_back(a);
            last = a;
        }
    }
    ll ans = 0;
    map<ll,ll,greater<ll>> mp;
    mp[X] = 1;
    for(auto a:A){
        auto it = mp.begin();
        while(it != mp.end()) {
            auto x = it->first;
            auto v = it->second;
            if(x < a) break;
            it = mp.erase(it);
            ll p = x/a;
            ans += p * v;
            ll q = x%a;
            mp[q] += v;
            if(p>0) mp[a-1] += p*v;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}