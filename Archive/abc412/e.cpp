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
    ll L,R;
    cin>>L>>R;
    
    ll ans = 0;
    vector<bool> isPrime(2E7, true);
    vector<bool> prime_1(R-L+1, true);
    for(ll e = 2; e*e <= R+10; e++){
        if(!isPrime[e]) continue;        
        for(ll x = 2*e; x*x <= R+10; x += e) {
            isPrime[x] = false;            
        }
        ll st = (L-1+e)/e;
        if(st==1) {
            st = 2*e;
        } else {
            st *= e;
        }
        for(ll x = st; x <= R; x += e) {
            prime_1[x - L] = false;
        }
    }
    for(auto e: prime_1) if(e) ans++;

    if(!prime_1[0]) {
        ans++;
        prime_1[0] = true;
    }
    for(ll i=2; i<isPrime.size(); i++) {
        if(!isPrime[i]) continue;
        ll x = i*i;
        while(x <= R) {
            if(x >= L && !prime_1[x-L]) ans++;
            x *= i;
        }
    }

    cout<<ans<<endl;
    return 0;
}