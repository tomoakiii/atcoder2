#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, Q;
    cin >> N >> Q;    
    ll lh=0, rh=1;

    ll ans = 0;
    while(Q--){
        char c;
        ll nx;
        cin >> c >> nx;
        nx--;
        int x, y;
        if(c=='L') {
            x = lh, y = rh;
        } else {
            x = rh, y = lh;
        }

        ll cnt = INF;
        ll tcnt = 0;
        ll x2 = x;
        bool  error = false;
        if (nx == x) {
            continue;
        }
        while(true) {
            x2++;
            if (x2 >= N) x2 = 0;
            if(x2 == y) {
                error = true;
                break;
            }
            tcnt++;
            if (x2 == nx) break;
        }
        if (!error) chmin(cnt, tcnt);
        tcnt = 0;
        x2 = x;
        error = false;
        while(true) {
            x2--;
            if (x2 < 0) x2 = N-1;            
            if(x2 == y) {
                error = true;
                break;
            }
            tcnt++;
            if (x2 == nx) break;
        }
        if (!error) chmin(cnt, tcnt);
        ans +=  cnt;
        if(c=='L') {
            lh = nx;
        } else {
            rh = nx;
        }        
    }
    cout << ans << endl;
    
    return 0;
}