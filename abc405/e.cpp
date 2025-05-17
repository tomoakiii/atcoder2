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
typedef modint998244353 mint;
int main(){
    ll A, B, C, D;
    cin>>A>>B>>C>>D;

    map<ll, unordered_map<ll, mint>> mpp;
    map<ll, mint> mpf;

    mint ans = 0;
    for(ll k = 0; C-1-k>=0; k++) {
        mint p = comb(A+k+2, B);
        if(D-1 == 0) ans += p;
        else ans += p * comb(C-k, D-1);
    }
    
    mint ans2= comb(A+1, B);
    if(D-1>0)ans2 = comb(A+1, B) * comb(C+1, D-1);
    ans = ans + ans2;
    cout << ans.val() << endl;
    return 0;
}