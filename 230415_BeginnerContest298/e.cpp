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
    int N,A,B,P,Q;
    cin >> N >> A >> B >> P >> Q;
    vector A(N, 0);

    ll sm = 0;
    rep(i, N) {
        cin >> A[i];
        sm += A[i];
    }
    
    cout << sm << endl;
    return 0;
}