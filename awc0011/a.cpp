#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N,M,S,T; cin>>N>>M>>S>>T;
    deque<pair<ll,ll>> PV(M);
    rep(i,M) {
        cin>>PV[i].first>>PV[i].second;
    }
    sort(PV.begin(),PV.end());
    if(T<S) swap(S,T);
    while(!PV.empty() && PV.begin()->first < S) PV.pop_front();
    while(!PV.empty() && PV.back().first > T) PV.pop_back();
    ll ans = 0;
    for(auto [p,v]:PV) ans+=v;
    cout<<ans<<endl;
    return 0;
}