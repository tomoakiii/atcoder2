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
    ll N,W;
    cin >> N >> W;
    vector<pair<ll,ll>> AB(N);
    rep(i,N) {
        cin>>AB[i].first>>AB[i].second;
    }
    sort(AB.rbegin(), AB.rend());

    ll ans = 0;
    for(auto [a,b] : AB) {
        if(b < W) {
            W-=b;
            ans += b*a;
        } else {
            ans += W*a;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}