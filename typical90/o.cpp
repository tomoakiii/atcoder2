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

using S = mint;
using F = mint;
S op(S l, S r) {return max(l, r);}
S e() {return 0;}
S mapping (F l, S r) {return r+=l;}
F composition (F l, F r) {return l+r;}
F id() {return 0;}
typedef modint1000000007 mint;




int main(){
    ll N;
    cin >> N;
    rep(k,N) {
        for(ll a=1; a<=N; a++) {
            ans += Comb(N-(k)*(a-1), a);
        }
    }
    cout << ans << endl;
    return 0;
}