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
    ll A,B,K; cin>>A>>B>>K;
    set<ll> st;
    for(int i=1;i<A+B;i++) {
        if(A%i==0 && B%i ==0) st.insert(i);
    }
    while(st.size()>K) st.erase(st.begin());
    cout<<*st.begin()<<endl;
    return 0;
}