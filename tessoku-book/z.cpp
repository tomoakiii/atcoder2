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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll Q; cin>>Q;
    ll M = 300000;
    vector<bool> isPrime(M+1, true);
    for(ll i=2; i<=M; i++) {
        if(!isPrime[i]) continue;
        for(ll k = 2; k*i <= M; k++) {
            isPrime[i*k] = false;
        }
    }
    while(Q--) {
        ll x; cin>>x;
        if(isPrime[x]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}