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
    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    while(A != B) {
        if (B>A) swap(A,B);
        ll d = A-B;
        ll p = d/B;
        if (d%B != 0) {
            p++;
        }
        ans += p;
        A -= B * p;
    }
    
    cout << ans << endl;
    return 0;
}