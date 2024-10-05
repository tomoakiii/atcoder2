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
        ll sm = 0;
        auto func = [&](auto func, ll x, ll k, ll from) -> void {
            ll nx;
            if (k == 0){
                sm += 1;
                return;
            }
            nx = 2*x+1;
            if (nx <= N && nx != from){
                func(func, nx, k-1, x);
            }
            nx = 2*x+2;
            if (nx <= N && nx != from){
                func(func, nx, k-1, x);
            }
            nx = (x-1)/2;
            if (x > 0 && nx != from) {
                func(func, nx, k-1, x);
            }
        };
        func(func, X, K, -1);
        cout << sm << endl;
    }
    return 0;
}