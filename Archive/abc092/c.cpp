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
    rep(i,N) cin>>A[i];
    vector<ll> D(N+1);
    ll x = 0;
    rep(i,N) {
        D[i+1] += D[i] + abs(A[i]-x);
        x = A[i];
    }
    D.push_back(D[N] + abs(A[N-1]));
    rep(i,N) {
        ll ans = D[N+1];
        ans -= D[i+2] - D[i];
        if(i==0) ans += abs(A[1]);
        else if(i==N-1) ans += abs(A[N-2]);
        else ans += abs(A[i+1] - A[i-1]);
        cout << ans << endl;
    }
    return 0;
}