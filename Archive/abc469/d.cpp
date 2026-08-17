#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
typedef long long ll;

int main(){
    ll N,M; cin>>N>>M;
    map<ll, set<ll>> mp;
    {
        ll a, b; cin>>a>>b; a--,b--;
        rep(i,N){
            if(a!=i){
                mp[a].insert(i);
                //mp[i].insert(a);
            }
            if(b != i){
                mp[b].insert(i);
                //mp[i].insert(b);
            }
        }
    }
    rep(i,M-1){
        ll a, b; cin>>a>>b; a--,b--;
        auto itm = mp.begin();
        while(itm != mp.end()){
            auto v = itm->first;
            if(v==a || v == b){

            } else {
                auto it = itm->second.begin();
                while(it != itm->second.end()){
                    if(*it != b && *it != a) it = itm->second.erase(it);
                    else it++;
                }
            }
            if(itm->second.empty()) itm = mp.erase(itm);
            else itm++;
        }
    }
    set<pair<ll,ll>> ans;
    for(auto [v, st] : mp) {
        for(auto j : st) {
            if(j>v) ans.insert({v,j});
            else if(j<v) ans.insert({j,v});
        }
    }
    cout<<ans.size()<<endl;
    return 0;
}
