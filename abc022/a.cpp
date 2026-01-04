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
    ll N,S,T,W; cin>>N>>S>>T>>W;
    ll ans = 0;
    if(S<=W&&W<=T)ans++;
    rep(i,N-1) {
        ll a; cin>>a; W+=a;
        if(S<=W&&W<=T)ans++;
    }
    cout<<ans<<endl;
    return 0;
}