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
    ll N,M; cin>>N>>M;
    ll X,Y; cin>>X>>Y;
    ll st = 0;
    ll ans = 0;
    vector<ll> A(N), B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];

    while(true) {
        auto it = lower_bound(A.begin(), A.end(), st) - A.begin();
        if(it == N) break;
        st = A[it] + X;
        it = lower_bound(B.begin(), B.end(), st) - B.begin();
        if(it == M) break;
        st = B[it] + Y;
        ans++;
    }
    cout << ans << endl;

    return 0;
}