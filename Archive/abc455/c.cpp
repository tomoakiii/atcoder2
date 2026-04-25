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
    cin >> N >> K;
    map<ll,ll> mp;
    ll sm = 0;
    rep(i,N) {
        ll a; cin>>a;
        mp[a]++;
        sm+=a;
    }

    vector<ll> vc;
    for(auto [v,c]:mp) {
        vc.push_back(v*c);
    }

    sort(vc.begin(),vc.end());
    ll del=0;
    rep(i,K) {
        if(vc.size() > 0) {
            del+=vc.back();
            vc.pop_back();
        }
    }
    cout<<sm-del<<endl;
    return 0;
}