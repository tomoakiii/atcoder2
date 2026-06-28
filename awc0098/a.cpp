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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,D;
    cin >> N >> D;
    vector<ll> T(N);
    ll ans=0;
    rep(i,N)cin>>T[i];
    rep(i,N){
        ll sm=0;
        rep(j,D){
            ll t;cin>>t;
            sm+=abs(t-T[i]);
        }
        chmax(ans,sm);
    }
    cout<<ans<<endl;
    return 0;
}