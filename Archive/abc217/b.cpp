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
    set<string> st;
    st.insert("ABC");
    st.insert("ARC");
    st.insert("AGC");
    st.insert("AHC");
    rep(i,3) {
        string s; cin>>s; st.erase(s);
    }
    cout<<*st.begin()<<endl;
    return 0;
}