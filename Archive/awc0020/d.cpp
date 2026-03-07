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
    ll N,L;
    cin >> N >> L;
    vector<pair<ll,ll>> v;
    rep(i,N) {
        ll x,r; cin>>x>>r;
        v.push_back({x-r, x+r});
    }
    v.push_back({L,L+1});
    ll last = 0;
    sort(v.begin(),v.end());
    for(auto [v,b]:v) {
        if(v > last) {
            cout<<"No"<<endl;
            return 0;
        }
        chmax(last, b);
    }
    cout<<"Yes"<<endl;
    return 0;
}