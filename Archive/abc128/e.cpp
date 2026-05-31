#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

typedef long long ll;

int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<tuple<ll,ll,ll>> event;
    rep(i,N) {
        ll s,t,x; cin>>s>>t>>x;
        event.push_back(make_tuple(s-x,1,x));
        event.push_back(make_tuple(t-x,2,x));
    }
    vector<ll> ans(Q);
    rep(i,Q) {
        ll d; cin>>d;
        event.push_back(make_tuple(d,3,i));
    }
    sort(event.begin(),event.end());
    multiset<ll> st;
    for(auto [time, query, x]: event) {
        if(query == 1) {
            st.insert(x);
        } else if(query == 2){
            st.erase(st.find(x));
        } else {
            if(st.empty()) ans[x] = -1;
            else ans[x] = *st.begin();
        }
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}