#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    ll ans;
    if(N%4 != 0) ans = 365;
    else if(N%4 == 0 && N%100 != 0) ans = 366;
    else if(N%100 == 0 && N%400 != 0) ans = 365;
    else if (N%400 == 0 )ans = 366;    
    else ans = -1;

    cout << ans << endl;
    return 0;
}