#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll sm = 0;    
    rep(i, 64) {
        ll a;
        cin >> a;        
        sm += a * 1<<i;
    }
    
    cout << sm << endl;
    return 0;
}