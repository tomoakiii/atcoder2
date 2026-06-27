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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q,K;
    cin >> N >> Q >> K;
    vector<tuple<ll,int,ll>> v(N+Q);

    rep(i,N) {
        ll a,d; cin>>a>>d;
        if(a<=K) v[i]=make_tuple(0,0,i);
        else {
            if(d==0) {
                v[i]=make_tuple(INF,0,i);
            } else {
                ll t = (a-K+d-1)/d;
                v[i]=make_tuple(t,0,i);
            }
        }
    }
    rep(i,Q){
        ll t; cin>>t;
        v[i+N]=make_tuple(t,1,i);
    }
    sort(v.rbegin(),v.rend());
    vector<ll> anss(Q);
    set<pair<ll,ll>> st;
    st.insert({N-1,0});
    ll ans = N*(N+1)/2;
    for(auto [t,id,i]:v){
        if(id==0){
            auto it = st.lower_bound({i,0});
            auto [r,l] = *it;
            st.erase(it);
            ll di=r-l+1;
            ans -= di*(di+1)/2;
            if(r>=i+1) {
                st.insert({r,i+1});
                di = r-(i+1)+1;
                ans += di*(di+1)/2;
            }
            if(l<=i-1) {
                st.insert({i-1,l});
                di = (i-1)-l+1;
                ans += di*(di+1)/2;
            }
        } else {
            anss[i] = ans;
        }
    }
    for(auto a:anss) cout<<a<<endl;
    return 0;
}