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
    ll N;
    cin >> N;
    vector<ll> A(N, 0);
    vector<ll> B(N-1, 0);
    rep(i,N) cin>>A[i];
    rep(i,N-1) cin>>B[i];
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    ll pur = A[N-1];
    int ia = 0, ib = 0;
    bool skp = false;
    while(ia < N && ib < N) {
        if(A[ia] <= B[ib]) {
            ia++, ib++;
        } else {
            if (skp) {
                cout << -1 << endl;
                return 0;
            }
            pur = A[ia];
            ia++;
            skp = true;
        }
    }

    cout << pur << endl;
    return 0;
}