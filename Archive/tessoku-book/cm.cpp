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
typedef long double ld;
int main(){
    ll N,K; cin>>N>>K;
    ll N1=N/2;
    ll N2 = N-N1;
    vector<ll> A(N1),B(N2);
    unordered_set<ll> st;
    rep(i,N1) cin>>A[i];
    rep(i,N2) cin>>B[i];

    rep(k, 1ll<<N1) {
        ll sm = 0;
        rep(i,N1) {
            if(k>>i & 1) sm+=A[i];
        }
        st.insert(sm);
    }

    rep(k, 1ll<<N2) {
        ll sm = 0;
        rep(i,N2) {
            if(k>>i & 1) sm+=B[i];
        }
        if(st.contains(K-sm)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}