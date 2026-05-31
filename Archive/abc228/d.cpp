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
    const ll N = (ll)1<<20;
    vector<ll> A(N, -1);
    set<ll> st;
    rep(i,N) st.insert(i);
    int Q; cin>>Q;
    while(Q--) {
        ll t,X,x;
        cin>>t>>X;        
        x = X%N;
        if(t==1) {
            auto it = st.lower_bound(x);
            if(it == st.end()) {
                it = st.begin();
            }
            A[*it] = X;
            st.erase(it);
        } else {
            cout<<A[x]<<endl;
        }
    }
    return 0;
}