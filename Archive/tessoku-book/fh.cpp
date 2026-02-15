//https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bp
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
typedef modint1000000007 mint;
int main() {
    ll W; cin>>W; W--;
    mint x = 12;
    vector<mint> pow(100, 1);
    pow[1] = 7;
    rep(i,98) {
        pow[i+2] = pow[i+1] * pow[i+1];
    }
    int i = 0;
    while(W) {
        i++;
        if(W%2) x *= pow[i];
        W/=2;
    }
    cout << x.val() << endl;
    return 0;
}