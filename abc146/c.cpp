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
    ll A,B,X;
    cin >> A >> B >> X;
    auto check = [&](ll x)->bool{
        ll d = 0;
        ll xx = x;
        while(xx) {
            d++;
            xx /= 10;
        }
        ll y = A*x + B*d;
        return (y <= X); 
    };
    if(!check(1)) {
        cout << 0 << endl;
        return 0;
    }
    ll mx = 1e9;
    if(check(mx)) {
        cout << mx << endl; 
        return 0;
    }
    ll ok = 1, ng = mx;
    while(ng - ok > 1) {
        ll c = (ok+ng)/2;
        if(check(c)) ok = c;
        else ng = c;
    }
    cout << ok << endl;
    return 0;
}