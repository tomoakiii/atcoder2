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
    ll X;
    cin >> X;
    for(ll S0=1; S0<=X; S0++) {
        if(X%S0 != 0) continue;
        ll S1 = X/S0;
        for(ll a = 1; a*a*a*a<=S1; a++) {
            ll b = a-S0;
            if(a*a*a*a+a*a*a*b+a*a*b*b+a*b*b*b+b*b*b*b == S1) {
                cout<<a<<" "<<b<<endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}