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
    vector<ll> A(N);
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
        A[i] += 3E5;
        A[i] -= i;
        sm += A[i];
    }
    sort(A.begin(), A.end());
    ll med = A[N/2];
    ll ans = 0;
    rep(i,N) {
        ans += abs(A[i]-med);
    }
    cout << ans << endl;
    return 0;
}