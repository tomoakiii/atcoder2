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
    ll A, X, M;
    cin >> A >> X >> M;
    ll S=0, K = 1;
    while(X) {
        if (X%2) {
            
        }
    }


    rep(i, X) {
        S += K;
        S %= M;
        K*=A;
    }
    
    cout << S << endl;
    return 0;
}