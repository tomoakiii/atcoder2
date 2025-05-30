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
    string S;
    int Q;
    cin >> S >> Q;
    while(Q--) {
        ll t, k;
        cin >> t >> k;
        k--;
        
        int st = t + popcount(k);
        st %= 3;
        char ans = S[k] + st;
        if(ans > 'C') ans -= 3;
        cout << ans << endl;
    }
    return 0;
}