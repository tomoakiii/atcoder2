#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main(){
    ll X,K,D; cin>>X>>K>>D;
    X = abs(X);
    ll p = X/D;
    if(p >= K) {
        cout << X - K*D;
        return 0;
    }
    X -= p*D;
    K -= p;
    if(K%2 == 0) {
        cout << X << endl;
    } else {
        cout << abs(X - D) << endl;
    }
    return 0;
}