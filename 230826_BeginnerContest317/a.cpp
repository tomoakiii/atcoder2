#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main()
{    
    ll N, H, X;
    cin >> N >> H >> X;
    for (ll i = 1; i<= N; i++){
        ll p;
        cin >> p;
        if (p + H >= X) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}