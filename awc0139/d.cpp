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
    ll N,H;
    cin >> N >> H;
    map<ll,ll> mp;
    fenwick_tree<ll> FT(N);
    rep(i,N)mp[i]=H;
    rep(i,N)FT.add(i,H);
    vector<pair<ll,int>> D(N);
    rep(i,N) {
        cin>>D[i].first;
        D[i].second=i;
    }
    sort(D.begin(),D.end());
    ll ans=0;
    for(auto [d,i]:D){
        if(FT.sum(0,i) < d) continue;
        ans++;
        auto it = mp.lower_bound(i);
        it--;
        while(d){
            if(it->second > d){
                it->second -= d;
                FT.add(it->first, -d);
                break;
            } else {
                d -= it->second;
                FT.add(it->first, -(it->second));
                it = mp.erase(it);
                it--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}