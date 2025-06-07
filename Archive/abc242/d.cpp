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
        ll t2 = t;
        ll nx = 1;
        while(t2--) {
            nx *= 2;
            if(nx > 1e18) {
                break;
            }
        }
        ll sz = nx;
        unsigned long long r = k % sz;
        unsigned long long q = k / sz;        
        unsigned long long x = popcount(r);
        cout << (char)((S[q] - 'A' + x + t) % 3 + 'A') << endl;
    }
    return 0;
}