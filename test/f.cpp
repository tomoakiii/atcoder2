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
    priority_queue<pair<ll,ll>> mp;
    mp.push({X, 1});
    for(auto a:A){
        while(!mp.empty()){ 
            auto [x,v] = mp.top();
            ll p = x/a;
            if(p==0) break;
            mp.pop();
            ans += p * v;
            ll q = x%a;
            mp.push({q, v});
            mp.push({(a-1), p*v});
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