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

int main(){
    ll N; cin>>N;
    vector<mint> A(N+1);
    A[1] = A[2] = 1;
    for(int i=3; i<=N; i++) {
        A[i] = A[i-1] + A[i-2];
    }
    cout << A[N].val() << endl;
    return 0;
}