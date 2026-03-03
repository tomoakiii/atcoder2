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
typedef pair<ll,ll> pll;
int main(){
    ll N,L,R,T;
    cin >> N >> L >> R >> T;
    pll mn={INF,INF};
    int ans=-1;
    rep(i,N) {
        ll p,s; cin>>p>>s;
        if(p<L || p>R || s<T) continue;
        if(chmin(mn, {p,-s})) ans=i+1;
    }
    cout<<ans<<endl;
    return 0;
}