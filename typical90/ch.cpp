#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
typedef long long ll;
typedef modint1000000007 mint;
int main(){
    int N, Q;    
    cin >> N >> Q;
    // const int M = 7;
    const int M = 60;
    vector BA(M, vector<int>(1<<N, 1));
    while(Q--){
        ll x, y, z, w;
        cin >> x >> y >> z >> w;
        x--, y--, z--;
        rep(i, M) {
            if (w>>i & 1) {
                rep(k, 1<<N) {
                    if ((k>>x & 1) == 0 && (k>>y & 1) == 0 && (k>>z & 1) == 0) {
                        BA[i][k] = 0;
                    }
                }
            } else {
                rep(k, 1<<N) {
                    if ((k>>x & 1) || (k>>y & 1) || (k>>z & 1)) {
                        BA[i][k] = 0;
                    }
                }
            }
        }
    }
    mint ans = 1;
    rep(i, M) {
        ll cnt = 0;
        rep(k, 1<<N) {
            if(BA[i][k] != 0) cnt++;
        }
        ans *= cnt;
    }

    cout << ans.val() << endl;
    return 0;
}