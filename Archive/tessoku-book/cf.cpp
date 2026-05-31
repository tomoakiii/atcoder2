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
typedef modint1000000007 mint;

int main() {
    int T; int N; cin>>T>>N;
    vector<int> P(T+2);
    rep(i,N) {
        int L,R; cin>>L>>R;
        P[L]++; P[R]--;
    }
    rep(i,T) {
        P[i+1] += P[i];
        cout << P[i] << endl;
    }
    return 0;
}