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
    ll N,Q;
    cin >> N >> Q;
    unordered_map<ll,ll> mp;
    vector<ll> dist;
    vector<pair<ll,ll>> NGs;
    int ind = 0;
    set<pair<ll,ll>> goes;
    goes.insert({0,INF});
    goes.insert({INF,INF});
    ll mns = 0, mnt = INF; // s too late is NG, t too early is NG
    rep(i,N) {
        ll s,t,x; cin>>s>>t>>x;
        if(!mp.contains(x)) {
            mp[ind] = x;
            dist.push_back(x);
            ind++;
        }
        s-=x;
        t-=x;
        auto it = goes.upper_bound({s, INF});
        auto it2 = it;
        it2--;
        auto [a,b] = *it2;
        set<pair<pair<ll,ll>, int>> ans;
        if(a == s) {
            if(t < b) {
                goes.erase(it2);
                goes.insert({t+1, b});
                ans.insert({{a,t},x});
            }else{
                goes.erase(it2);
                ans.insert({{a,b},x});
            }
        } else {
            if(b<s) {}
            else if(b<=t) {
                goes.erase(it2);
                goes.insert({a,s-1});
                ans.insert({{s,b},x});
            } else{
                goes.erase(it2);
                goes.insert({a,s-1});
                goes.insert({t+1,b});
                ans.insert({{s,t},x});
            }
        }
        while(true){
            auto it3 = goes.upper_bound({t,INF});
            auto [c,d] = *it;
            if(c<=t) {
                if(t<d){
                    goes.erase(it);
                    goes.insert({t+1,d});
                    break;
                }else{
                    goes.erase(it);
                }
            } else {
                break;
            }            
        }
    }

    while(D--){
        ll d; cin>>d;
        auto it = goes.lower_bound({d,0});
        auto [a,i] = 
    }
    return 0;
}