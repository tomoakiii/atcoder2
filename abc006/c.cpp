#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
        ll z2 = rm - 2*(N-y);
        if(z2%2==0 && y + z2/2 <= N) {
            int z = z2/2;
            int x = N-y-z;
            printf("%d %d %d\n", x, y, x);
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}