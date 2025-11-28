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
    vector<ll> A(N),C(N);    
    ll ans = 0;
    rep(i,N) cin>>A[i];
    rep(i,N) {
        ll b;
        cin>>b;
        ans += b;
    }
    rep(i,N-1) cin>>C[i];    
    rep(i,N-1) {
        if(A[i+1]-A[i] == 1) ans += C[A[i]-1];
    }
    cout<<ans<<endl;
    return 0;
}