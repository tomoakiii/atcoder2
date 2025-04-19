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
    ll N, A, B;
    cin >> N >> A >> B;
    if(B>A) swap(A, B);
    /* auto func = [&](ll x) -> ll {
        if(x == 1) return N * (N+1) / 2;
        ll p = N/x;
        ll e = x + x*(p-1);
        return p*(x+e)/2;
    }; */
    auto func = [&](ll x) -> ll {
        ll p = N/x;
        return x * p * (p+1) / 2;
        
    };
    if (A % B == 0) {
        cout << func(1) - func(A) << endl;        
    } else {
        cout << func(1) - (func(A) + func(B) - func(lcm(A,B))) << endl;
    }
//    cerr << func(1) << " " << func(A) << " " << func(B) << " " << func(A*B) << endl;
    return 0;
}