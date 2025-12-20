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
int main(){
    ll N;
    cin >> N;
    vector<bool> visit(N);
    vector<ll> X(N),R(N);
    unordered_map<ll,int> mp;
    dsu UF(N);
    rep(i,N) {
        ll x,r; cin>>x>>r;
        X[i]=x, R[i]=r;
        if(mp.contains(x+r)) {
            UF.merge(i, mp[x+r]);
        } else mp[x+r] = i;
        if(mp.contains(x-r)) {
            UF.merge(i, mp[x-r]);
        } else mp[x-r] = i;
    }

    ll ans = 0;
    for(auto g : UF.groups()) {
        set<ll> st;
        for(auto i : g) {
            st.insert(X[i]+R[i]);
            st.insert(X[i]-R[i]);
        }
        ans += min(st.size(), g.size());
    }
    cout << ans << endl;
    return 0;
}