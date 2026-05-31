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
    ll N,Q;
    cin >> N>>Q;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(), A.end());
    while(Q--) {
        ll x; cin>>x;
        int k = lower_bound(A.begin(), A.end(), x) - A.begin();
        cout << N - k << endl;
    }
    return 0;
}