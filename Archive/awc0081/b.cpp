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
    stack<pair<ll,ll>> st;
    ll p = 0;
    ll ans = 0;
    rep(i,N) {
        ll d, v; cin>>d>>v;
        st.push({d,v});
        while(!st.empty()){
            auto [d2,v2] = st.top();
            if(d2 <= p) {
                p += d2;
                ans += v2;
                st.pop();
            } else {
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}