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
    ll N;
    cin >> N;
    multiset<ll> st;
    rep(i,N) {
        ll a; cin>>a;
        st.insert(a);
    }
    st.insert(-INF);
    st.insert(INF);
    ll s = 0;
    ll ans = 0;
    rep(i,N){
        auto it1 = st.lower_bound(s);
        auto it2 = it1; it2--;
        ll d1 = abs(s-*it1);
        ll d2 = abs(s-*it2);
        if(d1 < d2) {
            ans += d1;
            s = *it1;
            st.erase(it1);
        } else {
            ans += d2;
            s = *it2;
            st.erase(it2);
        }
    }
    cout << ans << endl;
    return 0;
}