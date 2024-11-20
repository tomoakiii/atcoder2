#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    ll k = 2;
    auto pow = [&](ll c, ll k)->bool{
        ll x = 1;
        while(k--){
            x *= c;
        }
        if (x <= N) return true;
        else return false;
    };
    ll ans = 0;
    while(true) {
        ll ng = N+1;
        ll ok = 1;
        while(ng-ok>1) {
            ll c = (ok+ng)/2;
            bool isOK = pow(c, k);
            if (isOK) ok = c;
            else ng = c;
        }
        ans += (ok - 1);
        k++;
        if ((1<<k)>N) break;
    }
    cout << ans << endl;
    return 0;
}