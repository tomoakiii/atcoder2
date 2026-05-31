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
    int R, X;
    cin >> R >> X;
    
    if(X == 1) {
        if (R <= 2999 && R >= 1600) {
            cout << "Yes" << endl;
        } else cout << "No" << endl;
    } else {
        if (R <= 2399 && R >= 1200) {
            cout << "Yes" << endl;
        } else cout << "No" << endl;
    }

    return 0;
}