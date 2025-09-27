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
    ll n,a,b; cin>>n>>a>>b;
    auto ncr = [&n](ll a)->mint{
        mint tp = 1;
        for(ll i = n; i >= (n-a+1); i--){
            tp *= i;
        }
        mint dn = 1;
        for(ll i = 1; i <= a; i++) {
            dn *= i;
        }
        return tp/dn;
    };
    vector<ll> n2{};
    vector<mint> pp{};
    n2.push_back(1);    
    ll p = 1;
    mint ppp = 2;
    pp.push_back(2);
    while(p < n) {
        p*=2;
        n2.push_back(p);
        ppp = ppp*ppp;
        pp.push_back(ppp);
    }
    reverse(n2.begin(), n2.end());
    reverse(pp.begin(), pp.end());
    ll tn = n;
    mint nn = 1;
    rep(i,n2.size()){
        if(n2[i] <= tn) {
            tn -= n2[i];
            nn *= pp[i];
        }
    }
    mint ans = nn - 1 - ncr(a) - ncr(b);
    cout << ans.val() << endl;
    return 0;
}