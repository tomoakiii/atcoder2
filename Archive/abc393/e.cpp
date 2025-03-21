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
    ll N, K;
    const ll M = 1e6+2;
    cin >> N >> K;
    vector<ll> mp(M, 0);
    vector<ll> A(N);
    
    rep(i,N) {
        ll a;
        cin>>a;
        mp[a]++;
        A[i] = a;
    }

    vector<ll> dmx(M);    
    for(ll d = 1; d < M; d++) {        
        for(ll k = d; k < M; k+=d) {
            dmx[d] += mp[k];            
        }
    }
    
    vector<ll> best(M);
    for(ll d = 1; d < M; d++) {
        if(dmx[d] < K) continue;
        for(ll k = d; k < M; k+=d) {
            chmax(best[k], d);
        }
    }    
    rep(i,N) {
        printf("%lld\n", best[A[i]]);        
    }
    return 0;
}