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
    ll P; cin>>P;
    int cnt = 0;
    while(P) {
        ll fac = 1;
        for(ll p = 2; p < 100; p++) {
            if(fac*p > P) break;
            fac *= p;
        }
        P -= fac;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}