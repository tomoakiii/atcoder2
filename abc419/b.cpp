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
    int Q; cin>>Q;
    multiset<ll> st;
    while(Q--){
        int top; cin>>top;
        if(top == 1) {
            ll x; cin >> x;
            st.insert(x);
        } else {
            auto s = st.begin();
            cout << *s << endl;
            st.erase(s);
        }
    }
    
    return 0;
}