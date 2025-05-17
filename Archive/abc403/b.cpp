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
    string T, U;
    cin >> T >> U;
    rep(i, T.size()) {
        bool flg = true;
        rep(j, U.size()) {
            if(i+j>=T.size()) {
                flg = false;
                break;
            }
            if(T[i+j] != '?' && T[i+j] != U[j]) {
                flg = false;
            }
        }
        if(flg) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}