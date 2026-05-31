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
    ll N,M;
    cin >> N >> M;
    vector<ll>A(N);
    rep(i,N)cin>>A[i];
    multiset<ll> st;
    rep(i,M) {
        ll a; cin>>a; st.insert(-a);
    }
    ll ans=0;
    for(auto a:A){
        ll tgt=-2*a;
        auto it=st.lower_bound(tgt);
        if(it==st.end())continue;
        ans++;
        //cerr<<a<<" "<<(*it)/2<<endl;
        st.erase(it);
    }
    cout<<ans<<endl;
    return 0;
}