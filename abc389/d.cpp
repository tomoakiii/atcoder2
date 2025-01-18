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


double dist(double a, double b) {
    return a*a + b*b;
}

int main(){
    double R;
    cin >> R;
    double y = 0.5;
    double x = 0.5;
    ll ans = 1;
    rep(i, 1e6) {        
        y += 1;
        ans += 2;
        if (R*R < dist(x, y)) {
            y -= 1;
            ans -= 2;            
            break;
        }
    }
    
    ll yn = ans;
    rep(i, 1e6) {
        x += 1;
        while(R*R < dist(x, y)) {
            y -= 1;
            yn -= 2;
            if(yn <= 0) {
                cout << ans << endl;
                return 0;
            }
        }
        ans += 2*yn;
    }
    return 0;
}