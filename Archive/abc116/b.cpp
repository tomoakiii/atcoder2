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
    ll s; cin>>s;
    unordered_set<ll> st;
    st.insert(s);
    for(ll k=2; k<2e6; k++) {
        if(s%2 == 0) s = s/2;
        else s = 3*s + 1;
        if(st.contains(s)) {
            cout<<k<<endl;
            return 0;
        }
        st.insert(s);
    }
    cerr << "Fail" << endl;
    return 0;
}