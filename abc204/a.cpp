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
    ll x,y; cin>>x>>y;
    if(x==y) {
        cout<<x<<endl; return 0;
    }
    set<int> st; rep(i,3)st.insert(i); st.erase(x); st.erase(y); cout<<*st.begin()<<endl;
    return 0;
}