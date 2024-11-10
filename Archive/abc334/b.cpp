#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll A, M, L, R;
    cin >> A >> M >> L >> R;
    L-=A, R-=A;
    ll mx=0;
    if (L<0) {
        mx = 10 + (-1*L) / M;
    }
    L += M*mx;
    R += M*mx;
    cout << ((R/M) - ((L-1)/M)) << endl;
    return 0;
}