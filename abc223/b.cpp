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
    string S; cin>>S; set<string> st; st.insert(S);
    rep(i,S.size()) {
        S.push_back(S[0]);
        S.erase(0,1);
        st.insert(S);
    }
    cout<<*st.begin()<<endl;
    cout<<*st.rbegin()<<endl;
    return 0;
}