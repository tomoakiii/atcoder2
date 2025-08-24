#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
typedef long long ll;

int main(){    
    ll N, D, ans=0;
    cin >> N >> D;    
    rep(i,N) {
        ll p, q; cin >> p >> q;
        if(p*p+q*q <= D*D) ans++;
    }
    cout << ans << endl;
    return 0;
}