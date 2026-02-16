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
    ll N,K,M;
    cin >> N >> K >> M;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ans = 0;
    ll sm = A[0];
    ll r = 0;
    rep(l, N) {
        if(r>=N) break;
        while(r-l+1 < K || sm < M) {
            r++;
            if(r >= N) break;
            sm += A[r];
        }
        ans += N-r;
        sm -= A[l];
    }
    cout << ans << endl;
    return 0;
}