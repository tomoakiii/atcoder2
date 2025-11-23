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
    cin>>S;
    int ln = -INFi, lc = 0;
    int nn = -1, nc = 0;
    ll ans = 0;
    for(auto c : S) {
        int i = c - '0';
        if(i == nn) {
            nc++;
        } else {
            ln = nn;
            lc = nc;
            nn = i;
            nc = 1;
        }
        if(nn == ln + 1 && nc <= lc) {
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}