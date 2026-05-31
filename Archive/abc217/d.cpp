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
    ll L,Q; cin>>L>>Q;
    set<ll> st1, st2;
    st1.insert(0);
    st1.insert(L);
    st2.insert(0);
    st2.insert(-L);

    while(Q--) {
        int c; ll x;
        cin>>c>>x;
        if(c==1) {
            st1.insert(x);
            st2.insert(-x);            
        } else {
            ll s1 = *st1.upper_bound(x);
            ll s2 = *st2.upper_bound(-1*x) * -1;
            cout << s1 - s2 << endl;
        }
    }
    return 0;
}