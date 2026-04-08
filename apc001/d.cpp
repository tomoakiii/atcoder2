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
    ll N,M; cin>>N>>M;
    vector<ll>A(N);
    rep(i,N)cin>>A[i];
    dsu UF(N);
    rep(i,M) {
        int u,v; cin>>u>>v;
        UF.merge(u,v);
    }
    vector<multiset<ll>> vs(N);
    rep(i,N) {
        int c = UF.leader(i);
        vs[c].insert(A[i]);
    }
    ll nm = 0;
    ll ans=0;
    multiset<ll> st;
    rep(i,N) {
        if(vs[i].empty())continue;
        ans+=*vs[i].begin();
        vs[i].erase(vs[i].begin());
        nm++;
        st.merge(vs[i]);
    }
    if(nm==1) {
        cout<<0<<endl;
        return 0;
    }
    if(st.size()<nm-2) {
        cout<<"Impossible"<<endl;
        return 0;
    }
    auto it=st.begin();
    rep(i,nm-2) {
        ans+=*it;
        it++;
    }
    cout<<ans<<endl;
    return 0;
}