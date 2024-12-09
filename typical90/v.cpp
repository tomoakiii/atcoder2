#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(){
    ll A,B,C;
    cin >> A >> B >> C;
    ll ab = gcd(A,B);
    ll bc = gcd(C,B);
    ll g = gcd(ab, bc);

    cout << (A/g + B/g + C/g - 3) << endl;
    return 0;
}