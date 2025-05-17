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
    ll N, M;
    cin >> N >> M;
    vector<ll> S(M+1);
    ll p = 1, sm = 1;
    rep(i, M) {
        p *= N;
        if(p > 1E9) {
            cout << "inf" << endl;
            return 0;
        }
        sm += p;
        if(sm > 1E9) {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << sm << endl;
    return 0;
}