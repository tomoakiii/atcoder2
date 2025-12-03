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
    vector<ll> X2, X1;
    rep(i,N) {
        ll x; cin>>x;
        if(x >= 0) X1.push_back(x);
        else X2.push_back(-x);
    }
    reverse(X2.begin(), X2.end());
    ll ans = INF;
    if(X1.size() >= K && !X1.empty()) chmin(ans,X1[K-1]);
    if(X2.size() >= K && !X2.empty()) chmin(ans,X2[K-1]);
    rep(i, min(K, (ll)X1.size())) {
        if(0 <= K-i-2 && K-i-2 < X2.size() ) {
            ll l = X1[i];
            ll r = X2[K-i-2];
            chmin(ans,2*l+r);
            chmin(ans,2*r+l);
        }
    }
    cout<<ans<<endl;

    return 0;
}