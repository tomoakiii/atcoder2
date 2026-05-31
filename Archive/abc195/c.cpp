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
    ll ans = 0;
    if(N<1e3) {
        cout<<ans<<endl;
        return 0;
    }
    if(N<1e6) {
        cout<<(ll)(N-1e3+1)<<endl;
        return 0;
    }
    ans+=1e6-1e3;
    if(N<1e9) {
        cout<<ll(ans+2*(N-1e6+1))<<endl;
        return 0;
    }
    ans+=2*(1e9-1e6);
    if(N<1e12) {
        cout<<ll(ans+3*(N-1e9+1))<<endl;
        return 0;
    }
    ans+=3*(1e12-1e9);
    if(N<1e15) {
        cout<<ll(ans+4*(N-1e12+1))<<endl;
        return 0;
    }
    ans+=4*(1e15-1e12);
    ans+=5;
    cout<<ans<<endl;
    
    return 0;
}