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
    ll N,Q;
    cin >> N >> Q;
    set<pll> st;
    st.insert({-INF,-INF});
    st.insert({INF,INF});
    ll ans = N;
    while(Q--) {
        ll l, r; cin>>l>>r; r++;
        ll ex = 0;
        auto s = st.lower_bound({l, -INF});
        auto pr = s;
        pr--;
        if(pr->second >= r) {
            cout<<ans<<endl;
            continue;
        }
        if(pr->second >= l) {
            l = pr->first;
            ex += pr->second - pr->first;
            st.erase(pr);
        }
        ll fl = r-l;
        while(s != st.end()) {
            if(s->first > r) break;
            if(s->second <= r) {
                ex += s->second - s->first;
                s = st.erase(s);
            } else {
                ex += r - s->first;
                r = s->second;
                s = st.erase(s);
                break;
            }
        }
        st.insert({l,r});
        ans -= (fl - ex);
        cout<<ans<<endl;
    }
    return 0;
}