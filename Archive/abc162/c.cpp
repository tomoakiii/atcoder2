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
    ll K; cin>>K;
    ll sm = 0;
    for(ll a=1;a<=K; a++) {
        for(ll b=1; b<=K; b++){
            for(ll c=1; c<=K; c++) {
                sm += gcd(a, (gcd(b,c)));
            }
        }
    }
    cout << sm << endl;
    return 0;
}