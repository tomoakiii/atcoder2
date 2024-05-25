#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, L, R;
    cin >> N >> L >> R;
    ll st = L;
    ll ans = 0;
    while (true) {
        ll js, is, k;
        for (k=18; k>=0; k--) {
            if ((st % (1<<k)) != 0) continue;
            is = (1<<k);
            js = st/is;
            if (is*(js+1)-1 > R) continue;
            cout << "? " << k << " " << js << endl;
            break;
        }
        ll a;
        cin >> a;
        a = a% 100;
        ans+=a;
        if (is*(js+1)-1 == R ) break;
        st = is*(js+1);
    }
    ans = ans%100;
    cout << "! " << ans << endl;
    return 0;
}