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
    int Q;
    cin >> Q;
    multiset<ll> st;
    st.insert(INF);
    st.insert(-1);
    while(Q--){
        int t;
        ll x;
        cin >> t >> x;
        if(t==1) {
            st.insert(x);
        } else if (t==2) {
            int k;
            cin >> k;
            auto it = st.upper_bound(x);
            it--;
            ll ans = -1;
            while(*it != -1) {
                k--;
                if(k<=0) {
                    ans = *it;
                    break;
                }
                it--;
            }
            cout << ans << endl;
        } else {
            int k;
            cin >> k;
            auto it = st.lower_bound(x);            
            ll ans = -1;            
            while(*it != INF) {
                k--;
                if(k<=0) {
                    ans = *it;
                    break;
                }
                it++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
