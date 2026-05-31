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
    rep(i,K) {
        if(A+i<=B) st.insert(A+i);
        if(B-i>=A) st.insert(B-i);
    }
    for(auto s:st) cout<<s<<endl;
    return 0;
}