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
    ll N,K; cin>>N>>K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    ll ng = 0, ok = 1e9;
    while(ok-ng>1) {
        ll c = (ok+ng)/2;
        ll sm = 0;
        rep(i,N) sm += c/A[i];
        if(sm >= K) ok = c;
        else ng = c;
    }
    cout << ok << endl;
    return 0;
}