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
    ll N,K,D;
    cin >> N >> K >> D;
    ll ans=0;
    set<ll> st;
    vector<ll> X(N);
    rep(i,N){
        ll p; cin>>X[i]>>p;
        if(p>=K)st.insert(X[i]);
    }

    sort(X.begin(), X.end());
    st.insert(INF);
    st.insert(-INF);
    ll cov=-INF;
    for(auto x:X){
        if(x<=cov)continue;
        auto it = st.upper_bound(x+D);
        it--;
        if(*it+D<x || x+D<*it) {
            cout<<-1<<endl;
            return 0;
        }
        ans++;
        cov=*it+D;
    }
    cout<<ans<<endl;
    return 0;
}