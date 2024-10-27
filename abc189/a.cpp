#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INFl = 0x0F0F0F0F0F0F0F0F;
const ll INFi = 0x0F0F0F0F;

int main () {
    int N;
    ll X;
    cin >> N >> X;
    ll v, p, sm=0;
    for(int i=0; i<N; i++){
        cin >> v >> p;
        sm += v*p;
        if (X*100 < sm) {
            cout << (i+1) << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
