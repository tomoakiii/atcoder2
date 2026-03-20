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
    ll N; cin>>N;
    ll M=1e5+1;
    vector<map<int,ll>> v(M);
    rep(i,N) {
        int p,q; cin>>p>>q;
        p--,q--;
        v[p][q]++;
    }
    ll ans=0;
    rep(i,M) {
        ll sm=0;
        for(auto [v,n]:v[i]) sm+=n;
        for(auto [v,n]:v[i]) {
            ans += n*(sm-n);
        }
    }
    cout << ans/2 << endl;
    return 0;
}