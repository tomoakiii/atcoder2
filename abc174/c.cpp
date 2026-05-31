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
    ll K;
    cin >> K;
    ll M = 2E6;
    ll st = 7, ct = 1;
    rep(i,M) {
        if(st % K == 0) {
            cout << ct << endl;
            return 0;
        }
        st = st * 10 + 7;
        st %= K;
        ct++;
    }
    cout << -1 << endl;
    return 0;
}