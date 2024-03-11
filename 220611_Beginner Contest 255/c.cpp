#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    auto m = max(a, a + d * (n-1));
    if (x >= m) {
        cout << x - m << endl;
        return 0;
    }
    m = min(a, a + d * (n-1));
    if (x <= m) {
        cout << m - x << endl;
        return 0;
    }
    auto rem = abs((x-a) % d);
    if (rem > abs(d/2)) {rem = abs(d) - rem;}
    cout << rem << endl;

    return 0;
}

