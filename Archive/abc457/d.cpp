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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];

    __int128_t ok=1, ng=1e25;
    while(ng-ok>1) {
        __int128_t c = (ng+ok)/2;
        __int128_t sm = 0;
        rep(i,N) {
            __int128_t del = c - A[i];
            if(del<0) continue;
            __int128_t i1 = i+1;
            __int128_t p = (del + i1 - 1) / i1;
            sm += p;
        }
        if(sm > K) ng=c;
        else ok=c;
    }
    ll ans = ok;
    cout<<ans<<endl;
    return 0;
}