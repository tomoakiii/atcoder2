#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll A,B;
    cin >> A>>B;
    
    if (A==B) cout << 1 << endl;
    else if ((A-B)%2==0) cout << 3 << endl;
    else cout << 2 << endl;
    return 0;
}