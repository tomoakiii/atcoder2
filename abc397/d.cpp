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
    ll N;
    cin >> N;
    ll x = 2, y = 1;
    while(true) {
        ll p = x*x*x - y*y*y;
        if(p == N) {
            cout << x << " " << y << endl;
            return 0;
        }
        else if(p > N) {
            if(x-y > 1) {
                y++;
            } else {
                cout << -1 << endl;
                return 0;
            }
        } else {
            x++;
        }
    }

    return 0;
}