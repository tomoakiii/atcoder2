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
    ll N,D;
    cin >> N >> D;
    map<ll,ll> mp;
    ll ans = INF;
    map<ll,deque<ll>> ms;
    rep(i,N){
        ll a,c; cin>>a>>c;
        if(mp.contains(a)) chmin(mp[a],c);
        else mp[a]=c;
        ms[a].push_back(c);
        sort(ms[a].begin(), ms[a].end());
        if(ms[a].size()>2) ms[a].pop_back();
        if(a>=D)chmin(ans,c);
    }
    for(auto [x,st] : ms){
        if(x+x>=D){
            if(st.size()==2){
                ll sm=0;
                for(auto s:st)sm+=s;
                chmin(ans, sm);
            }
        }
    }
    auto mp2=mp;
    auto it=mp.end();
    it--;
    ll mn = INF;
    while(it!=mp.end()){
        auto [m,v]=*it;
        chmin(mn,v);
        it->second=mn;
        if(it==mp.begin())break;
        it--;
    }
    for(auto [a,v]:mp2){
        ll tgt = D-a;
        if(tgt>a){
            auto it2 = mp.lower_bound(tgt);
            if(it2!=mp.end()){
                auto [m2,v2] = *it2;
                chmin(ans,v+v2);
            }
        }
        if(a+a>=D){
            auto it2 = mp.upper_bound(a);
            if(it2!=mp.end()){
                auto [m2,v2] = *it2;
                chmin(ans,v+v2);
            }
        }
    }
    if(ans==INF)cout<<-1<<endl;
    else cout << ans << endl;
    return 0;
}