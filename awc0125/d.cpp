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
    ll N,D;
    cin >> N >> D;
    vector<pair<ll,ll>> PC;
    ll ans=-INF;
    rep(i,N) {
        ll p,c; cin>>c>>p;
        chmax(ans, p-c);
        if(p>c) PC.push_back({p, p-c});
    }
    sort(PC.begin(), PC.end());
    deque<pair<ll,ll>> st;
    ll sm = 0;
    for(auto [p,pc]:PC) {
        st.push_back({p, pc});
        sm += pc;
        while(!st.empty() && st.front().first+D < p) {
            sm -= st.front().second;
            st.pop_front();
        }
        chmax(ans, sm);
    }
    cout << ans << endl;
    return 0;
}