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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N+1), B(M+1);
    rep(i,N) cin>>A[i+1];
    rep(i,M) cin>>B[i+1];
    rep(i,N) A[i+1] += A[i];
    rep(i,M) B[i+1] += B[i];
    ll j = M;
    ll ans = 0;
    rep(i, N+1) {
        while(j>=0 && A[i] + B[j] > K) j--;
        if(j>=0)chmax(ans, i + j);    
    }
    cout << ans << endl;
    return 0;
}