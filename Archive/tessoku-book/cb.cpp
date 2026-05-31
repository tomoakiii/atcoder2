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
    ll N; cin>>N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    rep(i,N)for(int j=i+1; j<N; j++)for(int k=j+1; k<N; k++) {
        if(A[i]+A[j]+A[k] == 1000) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}