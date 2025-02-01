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
    ll N, A, B;
    cin >> N >> A >> B;
    auto func = [&](ll x) -> ll {
        if(x == 1) return N * (N+1) / 2;
        ll p = N/x;
        ll e = x + x*(p-1);
        return p*(x+e)/2;
    };
    if(A==1 || B==1) {
        cout << 0 << endl;
        return 0;
    } else if(N==1) {
        cout << 1 << endl;
        return 0;
    }
//    cerr << func(1) << " " << func(A) << " " << func(B) << " " << func(A*B) << endl;
    cout << func(1) - (func(A) + func(B) - func(A*B)) << endl;
    return 0;
}