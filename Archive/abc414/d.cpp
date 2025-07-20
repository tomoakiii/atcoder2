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
    set<ll> st;
    rep(i,N) {
        ll a;
        cin>>a;
        st.insert(a);
    }
    ll last = 0;
    vector<ll> G;
    for(auto s: st) {
        if(s != *st.begin()) G.push_back(s - last);
        last = s;
    }
    ll ans = 0;
    sort(G.begin(), G.end());
    rep(i,M-1) {
        if(G.size() > 0) G.pop_back();
    }
    for(auto g: G) ans += g;
    cout<<ans<<endl;
    return 0;
}