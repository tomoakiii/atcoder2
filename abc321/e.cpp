#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
int main(){
    int T;
    cin >> T;
    ll N, X, K;
    while(T--){
        cin >> N >> X >> K;
        N--;
        X--;
        ll ans = 0;
        ll p = 0, x0 = X, x1 + X;
        while(p < K) {
            x0 = 2*x0 + 1;
            x1 = 2*x1 + 1;
            p++;
            if(x0 > N) break;
        }
        if (p == K) {
            x1 = min(x1, N);
            if (x1 > x0) {
                ans += x1 - x0;
            }
        }
        p = 0; x0 = X;
        while(p < K && x0 > 0) {
            x0 /= 2;
            p++;
        }
        if(p == K) {
            
        }
        
        cout << sm << endl;
    }
    return 0;
}