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
    ll N;
    cin>>N;
    set<int> st;
    rep(i,2*N+1) st.insert(i+1);
    int r=*st.begin();
    cout<<r<<endl;
    st.erase(r);
    while(true){
        int x;
        cin>>x;
        st.erase(x);
        if(x==0) return 0;
        r=*st.begin();
        cout<<r<<endl;
        st.erase(r);
    }
    return 0;
}