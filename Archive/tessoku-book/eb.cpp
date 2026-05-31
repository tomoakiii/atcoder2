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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    set<ll> st;
    int Q; cin>>Q;
    while(Q--) {
        int q; ll x; cin>>q>>x;
        if(q==1) {
            st.insert(x);
        } else {
            if(st.empty()) cout<<-1<<endl;
            else {
                auto s = st.lower_bound(x);
                ll ans = abs(x - *s);
                s--;
                if(s != st.end()) {
                    chmin(ans, abs(x - *s));
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}