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
    vector<ll> A(N),B(N),C(M),D(M);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,M) cin>>C[i];
    rep(i,M) cin>>D[i];
    vector<pair<ll, pair<int,ll>>> v;
    rep(i,N) {
        v.push_back({A[i],{0,B[i]}});
    }
    rep(i,M) {
        v.push_back({C[i],{1,D[i]}});
    }
    sort(v.begin(),v.end());
    multiset<ll> st;
    for(auto [x, yb]:v){
        auto [b,y]=yb;
        if(b==0)st.insert(y);
        else{
            if(st.empty())continue;
            auto it=st.upper_bound(y);
            if(it==st.begin())continue;
            it--;
            st.erase(it);
        }
    }
    if(st.empty())cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}