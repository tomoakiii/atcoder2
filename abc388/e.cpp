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
    rep(i,N) {
        cin>>A[i];
    }
    ll ans = 0;
    ll lc = 0;
    ll rc = N/2;
    while(rc < N) {
        if(A[lc]*2 <= A[rc]) {
            ans++;
            lc++, rc++;
        } else {
            rc++;
        }
    }
    cout << ans << endl;
    return 0;
}