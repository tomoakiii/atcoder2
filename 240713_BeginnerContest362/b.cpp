#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll xa, xb, xc, ya, yb, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    ll pa = (xa-xb) * (xc-xb) + (ya-yb) * (yc-yb);
    ll pb = (xb-xa) * (xc-xa) + (yb-ya) * (yc-ya);
    ll pc = (xa-xc) * (xb-xc) + (ya-yc) * (yb-yc);
    if (pa == 0 || pb == 0 || pc == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}