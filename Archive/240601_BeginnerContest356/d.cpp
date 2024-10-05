#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;

int main(){
    ll N, M;
    cin >> N >> M;    
    //N++;
    mint ans = 0;
    for(int i=0; i<60; i++) {
        bool Ni = (N>>i) & 1, Mi = (M>>i) & 1;
        if (Mi) {
            ll p = 2ll << (i); // 2digit -> 2^3            
            ll r = N%p;            
            ans += (N-r)/2;
            if (r >= (1ll<<i)) ans += (r - (1ll<<i) + 1ll);
        }                
    }

    cout << ans.val() << endl;
    return 0;
}