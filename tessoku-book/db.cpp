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
typedef modint1000000007 mint;

int main(){
    ll a; ll b; cin>>a>>b;
    mint p = 1;
    vector<mint> P(100,1);
    P[1] = a;
    for(int i=2;i<=100;i++) P[i] = P[i-1] * P[i-1];
    mint ans = 1;
    int d = 1;
    while(b) {
        if(b%2) ans *= P[d];
        b/=2;
        d++;
    }
    cout << ans.val() << endl;
    return 0;
}