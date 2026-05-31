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
    ll N,T,A; cin>>N>>T>>A;
    ll mn = INF;
    A*=1000;
    T*=1000;
    int ans = -1;
    rep(i,N) {
        ll h; cin>>h;
        ll t = T - 6*h;
        if(chmin(mn, abs(t-A))) ans = i+1;
    }
    cout<<ans<<endl;
    return 0;
}