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

void solve(){
    ll X,Y,K;
    cin >> X >> Y >> K;
    map<ll,ll> mp;
    ll cnt=0;
    while(X){
        mp[X]=cnt;
        X/=K;
        cnt++;
    }
    mp[0]=cnt;
    cnt=0;
    ll ans=INF;
    while(Y){
        if(mp.contains(Y)) chmin(ans, mp[Y]+cnt);
        Y/=K;
        cnt++;
    }
    chmin(ans, mp[0] + cnt);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}