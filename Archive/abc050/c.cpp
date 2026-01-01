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
    rep(i,N) {
        cin>>A[i];
    }
    sort(A.begin(), A.end());
    vector<ll> vA(N);
    rep(i,N) {
        vA[i] = abs(N-1-i-i);
    }
    sort(vA.begin(), vA.end());
    rep(i,N) {
        if(vA[i] != A[i]) {
            cout << 0 << endl;
            return 0;
        }
    }
    mint ans = 1;
    rep(i,N/2) ans *= 2;
    cout << ans.val() << endl;
    return 0;
}