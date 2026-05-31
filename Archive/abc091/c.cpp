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
    vector<pair<pair<ll,int>, int>> AB;
    rep(i,N) {
        int a, b; cin>>a>>b;
        AB.push_back({{a,b}, 1});
    }
    vector<pair<ll,int>> CD;
    rep(i,N) {
        int a, b; cin>>a>>b;
        AB.push_back({{a,b}, 0});
    }
    sort(AB.begin(), AB.end());

    ll ans = 0;
    set<ll> st;
    for(auto [ab,x]: AB) {
        auto [a,b] = ab;
        if(x == 1) {
            st.insert(-b);
            continue;
        }
        auto s = st.lower_bound(-b);
        if(s == st.end()) continue;
        ans++;
        st.erase(s);
    }
    cout << ans << endl;
    return 0;
}