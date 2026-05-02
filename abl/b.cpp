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
    for(ll h=1; h<=3500; h++) {
        for(ll n=1; n<=3500; n++) {
            ll p = N*h*n;
            ll q = 4*h*n-N*n-N*h;
            if(q<=0) continue;
            if(p%q == 0) {
                ll w = p/q;
                cout << h << " " << n << " " << w << endl;
                return 0;
            }
        }
    }
    return 0;
}