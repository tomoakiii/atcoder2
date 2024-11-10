#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;

mint powpow(mint x, ll n) {
  if (n == 0) return 1;
  mint val = powpow(x, n / 2);
  val *= val;
  if (n % 2 == 1) val *= x;
  return val;
}


int main(){
    ll N;
    cin >> N;
    mint md = 1;
    auto N2 = N;
    while(N2>0){
        N2 /= 10;
        md = md * 10;
    }

    mint dn = powpow(md, N-1);
    dn = dn * md * mint(N);
    dn = dn - mint(N);
    dn = dn / (md-1);
    cout << dn.val() << endl;
    return 0;
}