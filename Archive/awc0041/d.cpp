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
    ll N,K;
    cin >> N>>K;
    vector<pair<ll,ll>> BA(N);
    rep(i,N)cin>>BA[i].second>>BA[i].first;
    sort(BA.begin(),BA.end());
    if(K==1) {
        ll ans=0;
        rep(i,N) {
            chmax(ans, BA[i].first*BA[i].second);
        }
        cout<<ans<<endl;
        return 0;
    }
    multiset<ll> st;
    rep(i,N) st.insert(BA[i].second);
    multiset<ll> sub;
    while(st.size()>K-1) {
        sub.insert(*st.begin());
        st.erase(st.begin());
    }
    ll sm=0;
    for(auto s:st) sm+=s;

    ll ans=0;
    rep(i,N) {
        auto [b,a] = BA[i];
        if(sub.contains(a)) {
            sub.erase(sub.find(a));
        }else {
            sm-=a;
            if(!sub.empty()) {
                auto it=sub.end(); it--;
                sm+=*it;
                st.insert(*it);
                sub.erase(it);
            } else {
                break;
            }
            st.erase(st.find(a));
        }
        chmax(ans, b*(sm+a));
    }
    cout<<ans<<endl;
    return 0;
}