#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    string S;
    cin >> S;
    map<char, ll> alib;
    ll mx = 0;
    for (auto c:S) {
        alib[c]++;
        mx = max(mx, alib[c]);
    }
    ll cnt=0;
    if (mx > 1) {
        cnt++;
    }
    ll L = S.size();
    for (auto it = alib.begin(); it != alib.end();it++){
        L -= it->second;
        cnt += it->second * L;
    }
    cout << cnt << endl;
    return 0;
}