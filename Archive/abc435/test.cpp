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
    set<ll> st;
    cout<<0<<" ";
    auto s = st.lower_bound(0);
    cout << ((s == st.begin())?"yes":"no") << " ";
    cout << ((s == st.end())?"yes":"no") << " ";

    if(s != st.end()) cout<<*s<<endl;
    else cout<<"NON"<<endl;

    st.insert(1);
    st.insert(3);
    rep(i,5) {
        cout<<i<<" ";
        auto s = st.lower_bound(i);
        cout << ((s == st.begin())?"yes":"no") << " ";
        cout << ((s == st.end())?"yes":"no") << " ";
        s--;
        if(s != st.end()) cout<<*s<<endl;
        else cout<<"NON"<<endl;
    }
    return 0;
}