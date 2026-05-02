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
    ll N,K; cin>>N>>K;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i]>>B[i];
    unordered_set<ll> st;
    st.insert(K);
    rep(i, 31) {
        ll p = 1ll<<i;
        if(K>>i & 1) {
            ll q = 1ll<<i;
            ll K2 = K - q;
            K2 |= (q-1);
            st.insert(K2);
        }
    }
    ll ans = 0;
    for(auto s:st) {
        ll sm = 0;
        rep(i,N) {
            if( (s | A[i]) == s ) sm+=B[i];
        }
        chmax(ans, sm);
    }
    cout << ans << endl;
    return 0;
}