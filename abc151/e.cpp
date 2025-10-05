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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(), A.end());
    mint mx = A[0];
    mint p = 2;
    for(int i=1; i<N; i++) {
        mx += p*A[i];
        p *= 2;
    }
    reverse(A.begin(), A.end());
    mint mn = A[0];
    p = 2;
    for(int i=1; i<N; i++) {
        mn += p*A[i];
        p *= 2;
    }
    cout << (mx-mn).val() << endl;
    return 0;
}