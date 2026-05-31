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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> R(N), B(N);
    R[N-1] = 1;
    for(int i=N-1; i>=1; i--) {
        R[i-1] += R[i];
        B[i] += X*R[i];
        R[i-1] += B[i];
        B[i-1] += Y*B[i];
    }
    cout << B[0] << endl;
    return 0;
}