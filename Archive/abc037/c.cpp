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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N+1);
    rep(i,N) cin>>A[i+1];
    rep(i,N) A[i+1] += A[i];
    ll ans = 0;
    for(int l=1, r=K; r<=N; l++, r++){
        ans += A[r] - A[l-1];
    }
    cout << ans << endl;
    return 0;
}