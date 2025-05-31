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
    ll T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        vector<ll> A(2*N);
        rep(i,2*N) cin>>A[i];
        multiset<ll> st;
        ll sm = 0;
        sm += A[0];
        st.insert(A[1]);
        for(int i=2; i<2*N; i+=2) {
            st.insert(A[i]);
            sm += *st.rbegin();            
            st.erase(st.find(*st.rbegin()));
            st.insert(A[i+1]);
        }        
        cout<<sm<<endl;
    }
    return 0;
}