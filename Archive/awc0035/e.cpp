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
    ll ans=0;
    ll last;
    cin>>last;
    deque<pll> st;
    st.push_back({last,1});
    rep(i,N-1) {
        ll a; cin>>a;
        pll key = {a,INF};
        auto id = upper_bound(st.begin(), st.end(), key) - st.begin();
        if(id<st.size()) {
            auto [b,cnt]=st[id];
          //  cerr<<cnt<<endl;
            ans+=cnt;
        }
        while(!st.empty() && st.begin()->first <= a) {
            st.pop_front();
        }
        if(st.empty()) st.push_back({a,1});
        else st.push_front({a,1+st.begin()->second});
    }
    cout<<ans<<endl;
    return 0;
}