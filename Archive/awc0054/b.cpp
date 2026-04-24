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
    ll N,W;
    cin >> N>>W;
    multiset<pair<ll,int>> st;
    rep(i,N) {
        ll l,w; cin>>l>>w;
        ll r=l+w;
        st.insert({l,1});
        st.insert({r,-1});
    }
    ll last=0;
    bool flg=false;
    ll ans=0;
    ll cnt=0;
    for(auto [m,v]:st){
        if(flg) ans+=m-last;
        cnt+=v;
        flg = (cnt>0);
        last=m;
    }

    cout<<ans<<endl;
    return 0;
}