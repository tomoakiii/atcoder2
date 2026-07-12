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
    ll N,Q;
    cin >> N >> Q;
    map<ll,vector<pair<int,string>>> mp;
    set<ll> st;
    rep(i,N){
        string s; ll v; cin>>s>>v;
        mp[v].push_back({i,s});
        st.insert(v);
    }
    while(Q--){
        ll x; cin>>x;
        if(mp.contains(x)){
            for(auto [j,s]:mp[x]){
                cout<<s<<" ";
            }
            cout<<endl;
        } else {
            auto r = st.lower_bound(x);
            auto l = r; l--;
            ll lv,rv;
            if(l == st.end()) lv=INF;
            else lv = abs(x-*l);
            if(r == st.end()) rv=INF;
            else rv = abs(x-*r);
            if(lv<rv) {
                auto [j,s] = *(mp[*l].begin());
                cout<<s<<endl;
            } else if(rv<lv) {
                auto [j,s] = *(mp[*r].begin());
                cout<<s<<endl;
            } else{
                auto [j1,s1] = *(mp[*l].begin());
                auto [j2,s2] = *(mp[*r].begin());
                if(j1<j2) cout<<s1<<endl;
                else cout<<s2<<endl;
            }
        }
    }
    return 0;
}