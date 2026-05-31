#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    ll T;
    cin >> T;
    ll N, X, K;
    while(T--){
        cin >> N >> X >> K;
        if(K == 0) {
            cout << 1 << endl;
            continue;
        }

        ll k = K;
        ll x = X;
        auto f = [&N](ll x, ll k)->ll{
            ll p = 1;
            ll s = x;
            while(k--) {
                p *= 2;
                s *= 2;
                if(s > N) return 0;
            }
            ll m = min(s + p - 1, N);
            return m - s + 1;
        };

        ll ans = f(x, K);
        while(x > 1) {
            ll pre = x;
            x /= 2;
            k--;
            if(k > 0) {
                ll y;
                if(2*x == pre) {
                    y = 2*x + 1;
                } else {
                    y = 2*x;
                }
                ans += f(y, k-1);
            } else if (k == 0) {
                ans++;
                break;
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}