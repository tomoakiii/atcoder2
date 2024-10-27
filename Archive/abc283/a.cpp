#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

typedef long long ll;

int main(){
    ll A,B;
    cin >> A >> B;
    ll p = 1;
    rep(i,B) {p*=A;}
    cout << p << endl;
    return 0;
}