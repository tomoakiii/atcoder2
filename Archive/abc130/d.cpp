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
    ll N, K; cin>>N>>K;
    vector<ll> A(N+1);
    rep(i,N) cin>>A[i+1];
    rep(i,N) A[i+1] += A[i];    
    ll ans = 0;
    for(int i=1; i<=N; i++) {
        if(A[N]-A[i-1] < K) continue;
        ll ng = i-1, ok = N;
        while(ok-ng>1) {
            ll c = (ok+ng)/2;
            if(A[c] - A[i-1] >= K) ok = c;
            else ng = c;
        }
        ans += N+1-ok;
    }
    cout << ans << endl;
    return 0;
}