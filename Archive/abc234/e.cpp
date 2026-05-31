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
    ll X;
    cin >> X;
    if(X<10) {
        cout << X << endl;
        return 0;
    }
    vector<int> P{};
    ll x = X;
    while(x) {
        P.push_back(x%10);
        x/=10;
    }
    reverse(P.begin(), P.end());
    ll a;
    for(int p = P[0]; p <= 9; p++) {
        for(int d = -9; d <= 9; d++) {
            a = p;
            int d2 = 0;
            for(int i=1; i<P.size(); i++) {                
                a *= 10;
                d2 += d;
                if(p + d2 < 0 || p + d2 > 9) {
                    a = 0;
                    break;
                }
                a += p + d2;
            }
            if(a >= X) {
                cout << a << endl;
                return 0;
            }
        }
    }
    return 0;
}