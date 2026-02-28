#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,K;
    cin >> N >> K;
    ll rK = ~K;
    ll ans = 0;
    ll sm = 0;
    rep(i,N) {
        ll a; cin>>a;
        if(a & rK) continue;
        sm |= a;
        ans++;
    }
    if(sm == K) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}