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
    ll N;
    cin >> N;
    ll M=1e6;
    vector<ll> mp(M+1);
    rep(i,N) {
        ll a;cin>>a;mp[a]++;
    }
    ll ans = 0;
    for(ll k=1; k<=M; k++) {
        ll sm=0;
        for(ll p=1; p*k<=M; p++){
            sm+=mp[p*k];
        }
        chmax(ans, sm*k);
    }
    cout<<ans<<endl;
    return 0;
}