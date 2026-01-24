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

// 2x + 4z = R
// 2(x+z) + 2z=R
// 2(N-y) + 2z = R

int main(){
    ll N,M;cin>>N>>M;
    rep(y, N) {
        ll rm = M - 3*y;
        if(rm%2!=0)continue;
        rm/=2;
        ll z = rm + y - N;
        ll x = N-y-z;
        if(x>=0 && y>=0 && z>=0 && x+y+z==N && 2*x+3*y+4*z == M) {
            printf("%lld %lld %lld\n", x, y, z);
            return 0;
        }

    }
    cout << "-1 -1 -1" << endl;
    return 0;
}