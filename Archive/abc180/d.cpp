#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll X,Y,A,B;
    cin >> X >> Y >> A >> B;
    ll ans = 0;
    while(true) {
        if(A < (B+X)/X && A<Y/X) {
            X = A*X;
            ans++;
        } else {
            break;
        }
    }    
    ans += (Y-X-1)/B;
    cout << ans << endl;
    return 0;
}