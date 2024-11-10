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
    vector<ll> A(N, 0); 
    ll total = 0;   
    rep(i, N) {
        cin >> A[i];
        total += A[i];
    }
    sort(A.begin(), A.end());
    vector B = A;
    A.insert(A.end(), B.begin(), B.end());
    ll sm = 0, smmx = 0;
    rep(i, 2*N-1) {
        if (A[i+1] == A[i] || A[i+1] == (A[i] + 1)%M ){
            sm += A[i+1];
        } else {
            sm = A[i+1];
        }
        chmax(smmx, sm);
    }
    if (smmx >= total) cout << 0 << endl;
    else cout << total-smmx << endl;
    return 0;
}